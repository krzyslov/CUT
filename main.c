#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>



struct sCpuData {
    unsigned int uiCpuIndx;
    float fCpuUsage;
    char cCPUname[6];
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};

void *reader(void *arg) 
{
    struct sCpuData * scd = (struct sCpuData*)arg;
    FILE *fp;
    char buff[255];
    while(1){
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
                
                //printf("%5s %d %d %d %d %d %d %d %d %d %d \n", cpun, user, nice, system, idle, iowait, irq, softirq, steal, guest, geust_nice);
            }
            fclose(fp);
        }
        sleep(1);
    }


    return NULL;
}

void *analyzer(void *arg)
{
    struct sCpuData scd = *(struct sCpuData*)arg;
    struct sCpuData prev_scd;
    int iPrevIdle, iPrevNonIdle, iPrevTotal;
    int iIdle, iNonIdle, iTotal;
    int iTotald, iIdled, iCPU_Percentage;
    while(1)
    {
        iPrevIdle = prev_scd.idle + prev_scd.iowait;
        iIdle = scd.idle + scd.iowait;

        iPrevNonIdle = prev_scd.user + prev_scd.nice + prev_scd.system + prev_scd.irq + prev_scd.softirq + prev_scd.steal;
        iNonIdle = scd.user + scd.nice + scd.system + scd.irq + scd.softirq + scd.steal;

        iPrevTotal = iPrevIdle + iPrevNonIdle;
        iTotal = iIdle + iNonIdle;

        //differentiate: actual value minus the previous one
        iTotald = iTotal - iPrevTotal;
        iIdled = iIdle - iPrevIdle;
        
        scd.fCpuUsage = iTotald - iIdled;
        scd.fCpuUsage /= iTotald;
        printf("%5s usage: %f %% \n", scd.cCPUname, scd.fCpuUsage);
        sleep(1);
    }

    return NULL;
}

void *printer(void *arg)
{
    struct sCpuData scd = *(struct sCpuData*)arg;
    
    while(1)
    {
        sleep(1);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    unsigned char ucCPUsNmbr = sysconf(_SC_NPROCESSORS_ONLN);
    pthread_t thread_reader, thread_analyzer, thread_printer;
    struct sCpuData scd;
    int result = pthread_create(&thread_reader, NULL, reader, &scd);
    if (result != 0) { perror("Could not create thread."); }
    result = pthread_create(&thread_printer, NULL, printer, &scd);
    if (result != 0) { perror("Could not create thread."); }
    result = pthread_create(&thread_analyzer, NULL, analyzer, &scd);
    if (result != 0) { perror("Could not create thread."); }

    while(1);
    //pthread_join(thread_reader, NULL);
    //printf("Main thread exiting.\n");

    return 0;
}