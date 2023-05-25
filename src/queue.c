#include "queue.h"


struct tailhead head;
unsigned char ucCPUsNmbr = 0;
unsigned char ucItemsInQueue = 0;

void add_to_CPUqueue(struct sCpuData scd_arg) {
    struct sCpuData *scd;
    scd = malloc(sizeof(struct sCpuData));
    if (scd == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(EXIT_FAILURE);
    }
    *scd = scd_arg; 
    TAILQ_INSERT_TAIL(&head, scd, nodes);
    scd = NULL;
    ucItemsInQueue++;
}

void empty_CPUqueue(){
     struct sCpuData *scd;

    while (!TAILQ_EMPTY(&head))
        {
            scd = TAILQ_FIRST(&head);
            TAILQ_REMOVE(&head, scd, nodes);
            free(scd);
            scd = NULL;
        }
    ucItemsInQueue = 0;
}

void clrscr() { printf("\e[1;1H\e[2J"); }

void print_CPUqueue(){
    struct sCpuData *scd;
    clrscr();
    TAILQ_FOREACH(scd, &head, nodes)
        {
            printf("%5s usage: %.4f %% \n", scd->cCPUname, scd->fCpuUsage);
        }
    
}