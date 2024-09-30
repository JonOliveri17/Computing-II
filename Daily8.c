#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
        PRIORITY_QUEUE pq = priority_queue_init_default();
        if (pq == NULL) {
            printf("Failed to initialize priority queue.\n");
            return 1;
        }

        
        priority_queue_insert(pq, 3, 12);
        priority_queue_insert(pq, 5, 77);
        priority_queue_insert(pq, 8, 200);
        priority_queue_insert(pq, 6, 150);

        //service and free
        while (!priority_queue_is_empty(pq)) {
            Status status;
            int data = priority_queue_front(pq, &status);
            if (status == SUCCESS) {
                printf("Front: %d\n", data);
                priority_queue_service(pq);
            }
        }

        priority_queue_destroy(&pq);

        return 0;
    }
