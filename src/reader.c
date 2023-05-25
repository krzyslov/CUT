#include "reader.h"

void *reader(void *arg) 
{
    FILE *fp;
    struct sCpuData scd = {0};
    unsigned char ucCpuCounter = 0;
    int BUFFER_SIZE = ucCPUsNmbr + 1;

    while(!end_signal){

        pthread_mutex_lock(&mutex);
        while (ucItemsInQueue == BUFFER_SIZE) {
            pthread_cond_wait(&reader_cond, &mutex);
        }
       
        fp= fopen("/proc/stat", "r");
        if(fp == NULL){
            printf("File cannot open \n");
        }else{

            char cCPUname[6];
            int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

            while (fscanf(fp,"%5s %d %d %d %d %d %d %d %d %d %d",
            cCPUname, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) != EOF)
            {
                if ( !strstr(cCPUname,"cpu"))
                {
                    ucCpuCounter = 0;
                    break;
                }
                strcpy(scd.cCPUname, cCPUname);
                scd.ucCpuIndx = ucCpuCounter; scd.user = user;
                scd.nice = nice; scd.system = system;
                scd.idle = idle; scd.iowait = iowait;
                scd.irq = irq; scd.softirq = softirq;
                scd.steal = steal; scd.guest = guest;
                scd.guest_nice = guest_nice;
                ucAnalyzeFinished = 0;
                ucCpuCounter++;
                add_to_CPUqueue(scd);
                
            }
            fclose(fp);
            
            
        }
        pthread_cond_signal(&analyzer_cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}