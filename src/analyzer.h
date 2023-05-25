#ifndef ANALYZER_THREAD_H
#define ANALYZER_THREAD_H

#include "queue.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

extern unsigned char ucCPUsNmbr;
extern volatile sig_atomic_t done;
extern pthread_mutex_t mutex;
extern unsigned char ucItemsInQueue;
extern unsigned char ucAnalyzeFinished;
extern pthread_cond_t printer_cond, analyzer_cond;

void *analyzer(void *arg);

#endif