#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/queue.h>    
#include <semaphore.h>        

sem_t mutex;
TAILQ_HEAD(tailhead, sCpuData) head;

struct sCpuData {
    unsigned int uiCpuIndx;
    float fCpuUsage;
    char cCPUname[6];
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    TAILQ_ENTRY(sCpuData) nodes;
};

void add_to_queue(struct sCpuData scd_arg) {
    struct sCpuData *scd;
    scd = malloc(sizeof(struct sCpuData));
    if (scd == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(EXIT_FAILURE);
    }
    
    //TAILQ_INSERT_HEAD(&head, scd, nodes);
    *scd = scd_arg; //e->c = string[c];
    TAILQ_INSERT_TAIL(&head, scd, nodes);
    scd = NULL;

}


void clrscr()
{
    printf("\e[1;1H\e[2J");
}



void *reader(void *arg) 
{
    struct sCpuData * scd = (struct sCpuData*)arg;
    FILE *fp;
    char buff[255];
    while(1){
        sem_wait(&mutex);
        fp= fopen("/proc/stat", "r");
        if(fp == NULL){
            printf("File cannot open \n");
        }else{

            //printf("File opened \n");
            char cpun[6];
            int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
            
            while (fscanf(fp,"%5s %d %d %d %d %d %d %d %d %d %d",
            cpun, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) != EOF)
            {
                if ( !strstr(cpun,"cpu"))
                    break;

                strcpy(scd->cCPUname, cpun);
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
                
                add_to_queue(*scd);
                //printf("%5s %d %d %d %d %d %d %d %d %d %d \n", cpun, user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
            }
            fclose(fp);
            
        }
        sem_post(&mutex);
        sleep(1);
    }


    return NULL;
}

void *analyzer(void *arg)
{
    struct sCpuData * scd; //(struct sCpuData*)arg;
    struct sCpuData prev_scd;
    int iPrevIdle, iPrevNonIdle, iPrevTotal;
    int iIdle, iNonIdle, iTotal;
    int iTotald, iIdled, iCPU_Percentage;
    
    while(1)
    {
        sem_wait(&mutex);
        //scd = head.tqh_first;
        //TAILQ_REMOVE(&head, head.tqh_first, entries);
        TAILQ_FOREACH(scd, &head, nodes)
        {
            
            //printf("%5s usage: %f %% \n", scd->cCPUname, scd->fCpuUsage);
        

            iPrevIdle = prev_scd.idle + prev_scd.iowait;
            iIdle = scd->idle + scd->iowait;

            iPrevNonIdle = prev_scd.user + prev_scd.nice + prev_scd.system + prev_scd.irq + prev_scd.softirq + prev_scd.steal;
            iNonIdle = scd->user + scd->nice + scd->system + scd->irq + scd->softirq + scd->steal;

            iPrevTotal = iPrevIdle + iPrevNonIdle;
            iTotal = iIdle + iNonIdle;

            //differentiate: actual value minus the previous one
            iTotald = iTotal - iPrevTotal;
            iIdled = iIdle - iPrevIdle;
            
            scd->fCpuUsage = iTotald - iIdled;
            scd->fCpuUsage /= iTotald;
            

            prev_scd = *scd;
        }

        //free(scd);
        sem_post(&mutex);
        sleep(1);
    }

    return NULL;
}

void *printer(void *arg)
{
    struct sCpuData * scd;// = (struct sCpuData*)arg;
    
    while(1)
    {
        sem_wait(&mutex);
        //scd = head2.tqh_first;
        //TAILQ_REMOVE(&head2, head2.tqh_first, entries);
        //printf("%5s usage: %f %% \n", scd->cCPUname, scd->fCpuUsage);
        TAILQ_FOREACH(scd, &head, nodes)
        {
            //printf("%c", e->c);
            printf("%5s usage: %f %% \n", scd->cCPUname, scd->fCpuUsage);
        }

        while (!TAILQ_EMPTY(&head))
        {
            scd = TAILQ_FIRST(&head);
            TAILQ_REMOVE(&head, scd, nodes);
            free(scd);
            scd = NULL;
        }

        clrscr();
        sem_post(&mutex);
        sleep(1);
        //free(scd);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    unsigned char ucCPUsNmbr = sysconf(_SC_NPROCESSORS_ONLN);
    pthread_t thread_reader, thread_analyzer, thread_printer;
    struct sCpuData scd;

    sem_init(&mutex, 0, 1);
    TAILQ_INIT(&head);

    int result = pthread_create(&thread_reader, NULL, reader, &scd);
    if (result != 0) { perror("Could not create thread."); }
    result = pthread_create(&thread_analyzer, NULL, analyzer, &scd);
    if (result != 0) { perror("Could not create thread."); }
    result = pthread_create(&thread_printer, NULL, printer, &scd);
    if (result != 0) { perror("Could not create thread."); }

    while(1);
    //pthread_join(thread_reader, NULL);
    //printf("Main thread exiting.\n");

    return 0;
}