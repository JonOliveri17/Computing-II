#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

void heapify_down(Priority_Queue* pq, int index)
{
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestChildIndex = index;
    
    if (leftChildIndex < pq->size && pq->array[leftChildIndex].priority_level > pq->array[largestChildIndex].priority_level)
    {
        largestChildIndex = leftChildIndex;
    }
    if (rightChildIndex < pq->size && pq->array[rightChildIndex].priority_level > pq->array[largestChildIndex].priority_level) {
        largestChildIndex = rightChildIndex;
    }

    // If smaller than child, swap and continue pushing down
    if (largestChildIndex != index) {
        my_swap(&pq->array[index], &pq->array[largestChildIndex]);
        heapify_down(pq, largestChildIndex);
    }
}


void heapify_up(Priority_Queue* pq, int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && pq->array[parent].priority_level < pq->array[index].priority_level) {
            my_swap(&pq->array[parent], &pq->array[index]);
            index = parent;
        }
    }

void my_swap(Node* n, Node* x)
{
    Node temp = *n;
    *n = *x;
    *x = temp;
}

PRIORITY_QUEUE priority_queue_init_default(void)
{
    Priority_Queue* pq = (Priority_Queue*)malloc(sizeof(Priority_Queue));
    if(pq == NULL)
    {
        return NULL;
    }
    pq -> capacity  = 10;
    pq -> size = 0;
    pq -> array = (Node*)malloc(sizeof(Node)*pq -> capacity);
    
    if(pq -> array == NULL)
    {
        free(pq);
        return NULL;
    }
    
    return pq;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Priority_Queue* pq = (Priority_Queue*)hQueue;
    if(pq -> size == pq -> capacity)
    {
        pq -> capacity *= 2;
        pq -> array = (Node*)realloc(pq -> array, sizeof(Node) * pq -> capacity );
        if(pq -> array == NULL)
        {
            return FAILURE;
        }
    }
    
    Node newNode;
    newNode.priority_level = priority_level;
    newNode.data = data_item;
    pq -> array[pq -> size] = newNode;
    heapify_up(pq, pq -> size);
    pq -> size++;
    
    
 
    
    return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    if(hQueue == NULL)
        return FAILURE;
    
    Priority_Queue* pq = (Priority_Queue*)hQueue;
    
    if(pq -> size == 0)
        return FAILURE;
    
    pq -> array[0] = pq -> array[pq -> size-1];
    pq -> size--;
    heapify_down(pq, 0);
    return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    if (hQueue == NULL || pStatus == NULL)
        return 0;
    
    Priority_Queue* pq = (Priority_Queue*)hQueue;
    if (pq -> size == 0)
    {
        *pStatus = FAILURE;
        return 0;
    }
    
    *pStatus = SUCCESS;
    return pq -> array[0].data;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    if(hQueue == NULL)
        return TRUE;
    
    Priority_Queue* pq = (Priority_Queue*)hQueue;

    return pq -> size == 0 ? TRUE : FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    if(phQueue == NULL || *phQueue == NULL)
        return;
    
    Priority_Queue* pq = (Priority_Queue*)*phQueue;
    free(pq->array);
    free(pq);
    *phQueue = NULL;
    
}
