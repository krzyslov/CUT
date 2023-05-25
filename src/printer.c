#include "printer.h"

void *printer(void *arg)
{
    struct sCpuData * scd;

    while(!done)
    {
        pthread_mutex_lock(&mutex);
        while( ucAnalyzeFinished == 0){
            pthread_cond_wait(&printer_cond, &mutex);
        }
        
        clrscr();

        TAILQ_FOREACH(scd, &head, nodes)
        {
            printf("%5s usage: %.4f %% \n", scd->cCPUname, scd->fCpuUsage);
        }
        while (!TAILQ_EMPTY(&head))
        {
            scd = TAILQ_FIRST(&head);
            TAILQ_REMOVE(&head, scd, nodes);
            free(scd);
            scd = NULL;
        }
        ucItemsInQueue = 0;
        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&reader_cond);
        sleep(1);
    }

    return NULL;
}