#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <sys/queue.h>    
#include <stdlib.h>
#include <stdio.h>

extern TAILQ_HEAD(tailhead, sCpuData) head;
extern unsigned char ucItemsInQueue;
//extern struct tailhead head;

struct sCpuData {
    unsigned char ucCpuIndx;
    float fCpuUsage;
    char cCPUname[6];
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    int prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq, prev_steal, prev_guest, prev_guest_nice;
    TAILQ_ENTRY(sCpuData) nodes;
};

void add_to_CPUqueue(struct sCpuData scd_arg);
void empty_CPUqueue();
void print_CPUqueue();


#endif
