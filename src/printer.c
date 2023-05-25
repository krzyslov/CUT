#include "printer.h"

void *printer(void *arg)
{
    struct sCpuData * scd;
    while(!end_signal)
    {
        pthread_mutex_lock(&mutex);
        while( ucAnalyzeFinished == 0){ // Data won't be printed unless analyzer thread finishes it's work
            pthread_cond_wait(&printer_cond, &mutex);
        }
        print_CPUqueue();
        empty_CPUqueue();
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&reader_cond);
        sleep(1);
    }
    pthread_exit(NULL);
}