#include "reader.h"



void *reader(void *arg) 
{
    struct sCpuData scd;
    unsigned char ucCpuCounter = 0;
    FILE *fp;
    //struct tailhead * head = (struct tailhead *) arg;
    int BUFFER_SIZE = ucCPUsNmbr + 1;
    while(!done){

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

                add_to_queue(scd);
                ucCpuCounter++;
                ucItemsInQueue++;
            }
            fclose(fp);
            
            
        }
        // Signal analyzer thread that data is ready
        pthread_cond_signal(&analyzer_cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);

    }


    pthread_exit(NULL);
}