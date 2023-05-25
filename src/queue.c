#include "queue.h"

//TAILQ_HEAD(tailhead, sCpuData) head;
struct tailhead head;
//struct tailhead head = TAILQ_HEAD_INITIALIZER(head);

void add_to_queue(struct sCpuData scd_arg) {
    struct sCpuData *scd;
    scd = malloc(sizeof(struct sCpuData));
    if (scd == NULL)
    {
        fprintf(stderr, "malloc failed");
        exit(EXIT_FAILURE);
    }
    *scd = scd_arg; 
    TAILQ_INSERT_TAIL(&head, scd, nodes); // &head
    scd = NULL;
}