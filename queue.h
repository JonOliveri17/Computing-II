#ifndef queue_h
#define queue_h
#include "status.h"
#include <stdio.h>

typedef void* QUEUE;

struct car
{
    int length;
    struct car *next;
};

struct car_queue
{
    struct car *front;
    struct car *rear;
};


QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE hQueue, int item);

int queue_front(QUEUE hQueue, Status* pStatus);

int queue_get_size(QUEUE hQueue);

Status queue_service(QUEUE hQueue);

Boolean queue_empty(QUEUE hQueue);
void queue_destroy(QUEUE* phQUeue);

#endif
