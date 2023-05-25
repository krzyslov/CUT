#include "analyzer.h"

unsigned char ucAnalyzeFinished;

void *analyzer(void *arg)
{   
    struct sCpuData * scd;
    unsigned char ucCpuIx = 0;
    struct sCpuData prev_scd[ucCPUsNmbr  + 1]; 
    { // Initialaze prev_scd with zeros to prevent memory leakage
        struct sCpuData scd_0 = {0};
        for (unsigned char ucCPUctr = 0; ucCPUctr < ucCPUsNmbr + 1; ucCPUctr++ )
        {
            prev_scd[ucCPUctr] = scd_0;
        }
    }

    int iPrevIdle = 0, iPrevNonIdle = 0, iPrevTotal = 0;
    int iIdle = 0, iNonIdle = 0, iTotal = 0;
    float fTotald = 0, fIdled = 0, fCPU_Percentage = 0;
    int BUFFER_SIZE = ucCPUsNmbr + 1;
    while(!end_signal)
    {
        pthread_mutex_lock(&mutex);
        while (ucItemsInQueue != BUFFER_SIZE || ucAnalyzeFinished == 1) { // Wait until reader thread finishes it's work
            pthread_cond_wait(&analyzer_cond, &mutex);
        }
        
        TAILQ_FOREACH(scd, &head, nodes)
        {
            ucCpuIx = scd->ucCpuIndx;

            iPrevIdle = prev_scd[ucCpuIx].idle + prev_scd[ucCpuIx].iowait;
            iIdle = scd->idle + scd->iowait;

            iPrevNonIdle = prev_scd[ucCpuIx].user + prev_scd[ucCpuIx].nice + prev_scd[ucCpuIx].system + 
            prev_scd[ucCpuIx].irq + prev_scd[ucCpuIx].softirq + prev_scd[ucCpuIx].steal;
            iNonIdle = scd->user + scd->nice + scd->system + scd->irq + scd->softirq + scd->steal;

            iPrevTotal = iPrevIdle + iPrevNonIdle;
            iTotal = iIdle + iNonIdle;

            fTotald = iTotal - iPrevTotal;
            fIdled = iIdle - iPrevIdle;
            scd->fCpuUsage = ((fTotald - fIdled)/fTotald)*100;
            
            ucAnalyzeFinished = 1;
            prev_scd[ucCpuIx] = *scd;
        }

        pthread_cond_signal(&printer_cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}