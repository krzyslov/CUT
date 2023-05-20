#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/queue.h>         

unsigned char ucCPUsNmbr;
pthread_mutex_t mutex;
pthread_cond_t reader_cond, analyzer_cond, printer_cond;
TAILQ_HEAD(tailhead, sCpuData) head;

int dataReady = 0;
int statsReady = 0;
int count = 0;
int calculated = 0;
int analyzed_before = 0;

struct sCpuData {
    unsigned char ucCpuIndx;
    float fCpuUsage;
    char cCPUname[6];
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    int prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq, prev_steal, prev_guest, prev_guest_nice;
    TAILQ_ENTRY(sCpuData) nodes;
    int calculated;
};

void add_to_queue(struct sCpuData scd_arg);
void clrscr();

void *reader(void *arg) 
{
    struct sCpuData * scd = (struct sCpuData*)arg;
    FILE *fp;
    unsigned char ucCpuCounter = 0;
    int BUFFER_SIZE = ucCPUsNmbr + 1;
    while(1){
        //printf("reader wait\n");
        pthread_mutex_lock(&mutex);
        
        while (count == BUFFER_SIZE) {
            //printf("count == BUFFER_SIZE [ %d ] reader \n", count);
            pthread_cond_wait(&reader_cond, &mutex);
        }
       

        fp= fopen("/proc/stat", "r");
        if(fp == NULL){
            printf("File cannot open \n");
        }else{

            char cpun[6];
            int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
            
            

            while (fscanf(fp,"%5s %d %d %d %d %d %d %d %d %d %d",
            cpun, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) != EOF)
            {
                if ( !strstr(cpun,"cpu"))
                {
                    ucCpuCounter = 0;
                    break;
                }
                strcpy(scd->cCPUname, cpun);
                scd->ucCpuIndx = ucCpuCounter;
                scd->user = user;
                scd->nice = nice;
                scd->system = system;
                scd->idle = idle;
                scd->iowait = iowait;
                scd->irq = irq;
                scd->softirq = softirq;
                scd->steal = steal;
                scd->guest = guest;
                scd->guest_nice = guest_nice;
                scd->calculated = 0;
                calculated = 0;

                add_to_queue(*scd);
                ucCpuCounter++;
                count++;
                //printf("%5s %d %d %d %d %d %d %d %d %d %d \n", cpun, user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
            }
            fclose(fp);
            
            
        }
        // Signal analyzer thread that data is ready
        pthread_cond_signal(&analyzer_cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
        //usleep(100000);
    }


    pthread_exit(NULL);
}

void *analyzer(void *arg)
{
    struct sCpuData * scd; //(struct sCpuData*)arg;
    //unsigned char ucCPUsNmbr = sysconf(_SC_NPROCESSORS_ONLN) + 1; // "+1" becouse i add first "cpu" data which is sumamry of all cpu's
    unsigned char ucCpuIx = 0;
    struct sCpuData prev_scd[ucCPUsNmbr + 1];
    float iPrevIdle, iPrevNonIdle, iPrevTotal;
    float iIdle, iNonIdle, iTotal;
    float iTotald, iIdled, iCPU_Percentage;
    int BUFFER_SIZE = ucCPUsNmbr + 1;
    while(1)
    {
        //printf("analyzer wait\n");
        pthread_mutex_lock(&mutex);
        //printf(">in analyzer \n");
        // Wait until data is ready

        while (count != BUFFER_SIZE || calculated == 1) {
            //printf("count !=  BUFFER_SIZE [ %d ] analyzer\n", count );
            pthread_cond_wait(&analyzer_cond, &mutex);
        }
        


        TAILQ_FOREACH(scd, &head, nodes)
        {
            ucCpuIx = scd->ucCpuIndx;
            //printf("%5s usage: %f %% \n", scd->cCPUname, scd->fCpuUsage);


            iPrevIdle = prev_scd[ucCpuIx].idle + prev_scd[ucCpuIx].iowait;
            iIdle = scd->idle + scd->iowait;

            iPrevNonIdle = prev_scd[ucCpuIx].user + prev_scd[ucCpuIx].nice + prev_scd[ucCpuIx].system + 
            prev_scd[ucCpuIx].irq + prev_scd[ucCpuIx].softirq + prev_scd[ucCpuIx].steal;
            iNonIdle = scd->user + scd->nice + scd->system + scd->irq + scd->softirq + scd->steal;

            iPrevTotal = iPrevIdle + iPrevNonIdle;
            iTotal = iIdle + iNonIdle;
            //printf("iPrevTotal: %f ", iPrevTotal );
            //printf("| iTotal: %f \n", iPrevTotal );
            //differentiate: actual value minus the previous one
            iTotald = iTotal - iPrevTotal;
            iIdled = iIdle - iPrevIdle;
            
            scd->fCpuUsage = ((iTotald - iIdled)/iTotald)*100;
            
            scd->calculated = 1;
            calculated = 1;
            prev_scd[ucCpuIx] = *scd;

        }

        
        
        pthread_cond_signal(&printer_cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    pthread_exit(NULL);
}

void *printer(void *arg)
{
    struct sCpuData * scd;// = (struct sCpuData*)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while( calculated == 0){
            pthread_cond_wait(&printer_cond, &mutex);
        }
        
        clrscr();
        

        TAILQ_FOREACH(scd, &head, nodes)
        {
            printf("%5s usage: %.4f %% \n", scd->cCPUname, scd->fCpuUsage);
            //printf("%5s %d %d %d %d %d %d %d %d %d %d cpu usage: %.4f %% %d\n", scd->cCPUname, scd->user, scd->nice, scd->system, scd->idle, scd->iowait, scd->irq, scd->softirq, scd->steal, scd->guest, scd->guest_nice, scd->fCpuUsage, scd->calculated);

        }
        while (!TAILQ_EMPTY(&head))
        {
            scd = TAILQ_FIRST(&head);
            TAILQ_REMOVE(&head, scd, nodes);
            free(scd);
            scd = NULL;
        }
        count = 0;
        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&reader_cond);
        sleep(1);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    ucCPUsNmbr = sysconf(_SC_NPROCESSORS_ONLN);
    pthread_t thread_reader, thread_analyzer, thread_printer;
    struct sCpuData scd;

    TAILQ_INIT(&head);

    

    pthread_cond_init(&reader_cond, NULL);
    pthread_cond_init(&analyzer_cond, NULL);
    pthread_cond_init(&printer_cond, NULL);
    
    
    int result = pthread_create(&thread_reader, NULL, reader, &scd);
    if (result != 0) { perror("Could not create thread."); }
    result = pthread_create(&thread_analyzer, NULL, analyzer, &scd);
    if (result != 0) { perror("Could not create thread."); }
    result = pthread_create(&thread_printer, NULL, printer, &scd);
    if (result != 0) { perror("Could not create thread."); }

    pthread_join(thread_reader, NULL);
    pthread_join(thread_analyzer, NULL);
    pthread_join(thread_printer, NULL);

    printf("Main thread exiting.\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&reader_cond);
    pthread_cond_destroy(&analyzer_cond);
    pthread_cond_destroy(&printer_cond);

    return 0;
}

void add_to_queue(struct sCpuData scd_arg) {
    struct sCpuData *scd;
    scd = malloc(sizeof(struct sCpuData));
    if (scd == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(EXIT_FAILURE);
    }
    *scd = scd_arg; 
    TAILQ_INSERT_TAIL(&head, scd, nodes);
    scd = NULL;
}

void clrscr()
{
    printf("\e[1;1H\e[2J");
}