#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "queue.h"
#include "reader.h"
#include "analyzer.h"
#include "printer.h"
#include "sigterm.h"

pthread_mutex_t mutex;
pthread_cond_t reader_cond, analyzer_cond, printer_cond;

int main() {
    
    pthread_t thread_reader, thread_analyzer, thread_printer;
    
    set_SIGTERM();
    set_SIGINT();
    
    ucCPUsNmbr = sysconf(_SC_NPROCESSORS_ONLN);

    TAILQ_INIT(&head);

    pthread_cond_init(&reader_cond, NULL);
    pthread_cond_init(&analyzer_cond, NULL);
    pthread_cond_init(&printer_cond, NULL);
    
    pthread_create(&thread_reader, NULL, reader, NULL);
    pthread_create(&thread_analyzer, NULL, analyzer, NULL);
    pthread_create(&thread_printer, NULL, printer, NULL);
    //pthread_create(&term3, NULL, term_after3sec, NULL); // do testow

    pthread_join(thread_reader, NULL);
    pthread_join(thread_analyzer, NULL);
    pthread_join(thread_printer, NULL);

    printf("\n Exiting the program.\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&reader_cond);
    pthread_cond_destroy(&analyzer_cond);
    pthread_cond_destroy(&printer_cond);

    return 0;
}