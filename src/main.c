#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include "queue.h"
#include "reader.h"
#include "analyzer.h"
#include "printer.h"


pthread_mutex_t mutex;
pthread_cond_t reader_cond, analyzer_cond, printer_cond;
unsigned char ucCPUsNmbr = 0;
unsigned char ucItemsInQueue = 0;
unsigned char ucAnalyzeFinished = 0;
volatile sig_atomic_t done = 0;

void clrscr() { printf("\e[1;1H\e[2J"); }
void term(int signum) { done = 1; }

void *term_after3sec();

int main() {
    
    pthread_t thread_reader, thread_analyzer, thread_printer, term3;
    
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);

    ucCPUsNmbr = sysconf(_SC_NPROCESSORS_ONLN);

    TAILQ_INIT(&head);

    pthread_cond_init(&reader_cond, NULL);
    pthread_cond_init(&analyzer_cond, NULL);
    pthread_cond_init(&printer_cond, NULL);
    
    pthread_create(&thread_reader, NULL, reader, NULL);
    pthread_create(&thread_analyzer, NULL, analyzer, NULL);
    pthread_create(&thread_printer, NULL, printer, NULL);
    pthread_create(&term3, NULL, term_after3sec, NULL); // do testow

    pthread_join(thread_reader, NULL);
    pthread_join(thread_analyzer, NULL);
    pthread_join(thread_printer, NULL);

    printf("\n Exiting the program using SIGTERM.\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&reader_cond);
    pthread_cond_destroy(&analyzer_cond);
    pthread_cond_destroy(&printer_cond);

    return 0;
}

void *term_after3sec()
{
    sleep(3);
    done = 1;
    return NULL;
}