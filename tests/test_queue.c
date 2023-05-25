#include <stdio.h>
#include <assert.h>
#include "../src/queue.h"

int main() {
    printf("Testing the add_to_CPUqueue function \n");
    int iDesiredQueueSize = 100;
    struct sCpuData scd = {0};
    TAILQ_INIT(&head);
    printf(">Create a queue of length %d \n", iDesiredQueueSize);
    for ( int iQueueCtr = 0; iQueueCtr < iDesiredQueueSize; iQueueCtr++ )
    {
        add_to_CPUqueue(scd);
    }

    assert(ucItemsInQueue == iDesiredQueueSize);

    printf(">Clear the queue \n");
    empty_CPUqueue();
    assert(ucItemsInQueue == 0 );
    
    printf("The test passed positively! \n");

    return 0;
}