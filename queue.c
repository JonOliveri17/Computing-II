#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


struct car* node(int l)
{
    struct car *temp = (struct car*)malloc(sizeof(struct car));
    
    temp -> length = l;
    temp -> next = NULL;
    
    return temp;
}

struct car_queue *init_default()
{
    struct car_queue *q = (struct car_queue*)malloc(sizeof(struct car_queue));
    q -> front = NULL;
    q -> rear = NULL;
    return q;
    
}

void queue_insert(struct car_queue *q, int l)
{
    struct car *temp = node(l);
    
    if (q -> rear == NULL)
    {
        q -> front = q -> rear = temp;
        return;
    }
    
    q -> rear -> next = temp;
    q -> rear = temp;
}

int check(struct car_queue *l, struct car_queue *r)

{
    if( l->front == NULL && r->front == NULL)
    {
        return 1;
    }
    
    return 0;
}


void car_queue_service(struct car_queue *q, int l)
{
    int sum = 0;
    
    if(q -> front == NULL)
    {
        return;
    }
    
    while(q -> front != NULL)
    {
        sum = sum + q -> front -> length;
        if(sum > l * 100)
        {
            break;
        }
        
        q -> front = q -> front -> next;
    }
    
    if (q -> front == NULL)
    {
        q -> rear = NULL;
    }
}
