/**********************************************************************
Program: Program 3
Author: Jonathan Olievri
Date: 04/23/2024
Time spent: 5 hours
Purpose: Allow basically any number for input below the max and cut out all duplicate items and then paste them in the correclty sorted order 
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "number_filter.h"

#define MAX 2000000000

int main(int argc, const char * argv[])
{
    FILE* fp;
    ARRAY hArray = NULL;
    int tempsize;
    int temp = 1;
    hArray = array_init_default();
    fp = stdin;
    
    do
    {
        fscanf(fp, "%d", &temp);
        
        if(temp != -1 && temp >= 0 && temp <= MAX)
        {
            array_insert(hArray, temp);
        }
    }while (temp != -1);
    
    array_filter(hArray);
    tempsize = array_size(hArray);
    bubble_sort(hArray, tempsize);
    
    for (int i = 0; i < array_size(hArray); i++)
    {
        printf("%d\n", *location(hArray, i));
    }
    
    array_destroy(&hArray);
    
    
    
    return 0;
}

void array_insert(ARRAY hTemp, int item)
{
    Array* pTemp = (Array*)hTemp;
    int* temp;
   
    if (pTemp -> size >= pTemp -> capacity)
    {
        temp = (int*)malloc(sizeof(int) * 2 * pTemp -> capacity);
        if (temp == NULL)
        {
            printf("failed allocation temp \n");
            exit(1);
        }
        
        for (int i = 0; i < pTemp -> size; i++)
        {
            temp[i] = pTemp -> data[i];
        }
        free(pTemp -> data);
        pTemp -> data = temp;
        pTemp -> capacity *= 2;
    }
    
    pTemp -> data[pTemp -> size] = item;
    pTemp -> size++;
}

void array_filter(ARRAY hTemp)
{
    Array* pTemp = (Array*)hTemp;
    
    int* temp;
    int* result;
    int flags;
    int count = 0;
    
    temp = (int*)malloc(sizeof(int) * pTemp -> capacity);
    temp[count] = pTemp -> data[0];
    count++;
    int tempsize;
    
    tempsize = pTemp -> size;
    
    for (int i = 1; i < tempsize; i++)
    {
        flags = 0;
        
        for (int n = 0; n < count; n++)
        {
            if(pTemp -> data[i] == temp[n])
            {
                flags = 1;
                pTemp -> size--;
                pTemp -> capacity--;
                break;
            }
        }
        
        if (flags == 1)
        {
            continue;
        }
        
        temp[count] = pTemp -> data[i];
        count++;
    }
    
    free(pTemp -> data);
    result = (int*)malloc(sizeof(int) * pTemp -> capacity);
    
    for(int m = 0; m < pTemp -> size; m++)
    {
        result[m] = temp[m];
    }
    
    pTemp -> data = result;
    
}

void array_destroy(ARRAY* phTemp)
{
    Array* pTemp = (Array*) *phTemp;
    free(pTemp -> data);
    free(pTemp);
    *phTemp = NULL;
}

ARRAY array_init_default(void)
{
    Array* pTemp;
    pTemp = (Array*)malloc(sizeof(Array));
    
    if(pTemp != NULL)
    {
        pTemp -> size = 0;
        pTemp -> capacity = 8;
        pTemp -> data = (int*)malloc(sizeof(int) * pTemp -> capacity);
        
        if(pTemp -> data == NULL)
        {
            free(pTemp);
            pTemp = NULL;
        }
    }
    
    return pTemp;
}

int array_size(ARRAY hTemp)
{
    Array* pTemp = (Array*) hTemp;
    return pTemp -> size;
}

int array_capacity(ARRAY hTemp)
{
    Array* pTemp = (Array*) hTemp;
    return pTemp -> capacity;
}

int* location(ARRAY hTemp, int index)
{
    Array* pTemp = (Array*) hTemp;
    if (index < 0 || index >= pTemp -> size)
    {
        return NULL;
    }
    
    return &pTemp -> data[index];
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(ARRAY hTemp, int size)
{
    Array* pTemp = (Array*) hTemp;
    int swapped = 1;
    int i = 1;
    
    for (int a = 0; a < size - 1 && swapped; i++)
    {
        swapped = 0;
        
        for (i = 0; i < size - 1; i++)
        {
            if(pTemp -> data[i] > pTemp -> data[i + 1])
            {
                swap(&pTemp -> data[i], &pTemp -> data[i + 1]);
                swapped = 1;
            }
        }
    }
}
