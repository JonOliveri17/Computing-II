/***********************************************************
Author: Jonathan Oliveri
Date: 03/27/2024
Effort: few hours of coding
Purpose: Design an interface that manages and changes and reads bit flags
***********************************************************/


#include "bit_flag.h"
#include <stdio.h>
#include <stdlib.h>
#define int_size (sizeof(int) * 8)

int main(int argc, char* argv[]) {
    
    BIT_FLAGS flags = bit_flags_init_number_of_bits(10);
    if (flags == NULL) {
        printf("Failed to initialize bit flags.\n");
        return 1;
    }

    
    bit_flags_set_flag(flags, 2);
    bit_flags_set_flag(flags, 5);

    
    printf("Flag at position 2: %d\n", bit_flags_check_flag(flags, 2));
    printf("Flag at position 5: %d\n", bit_flags_check_flag(flags, 5));
    printf("Flag at position 8: %d\n", bit_flags_check_flag(flags, 8));

    
    printf("Size of bit flags: %d\n", bit_flags_get_size(flags));
    printf("Capacity of bit flags: %d\n", bit_flags_get_capacity(flags));

    
    bit_flags_destroy(&flags);

    return 0;
}

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    if (number_of_bits <= 0)
        return NULL;
    
    struct Bit_flags* bit_flags = malloc(sizeof(struct Bit_flags));
    if (bit_flags == NULL)
    {
        return NULL;
    }
    
    bit_flags -> size = number_of_bits;
    bit_flags -> capacity = (number_of_bits + int_size - 1) / int_size;
    bit_flags -> data = calloc(bit_flags -> capacity, sizeof(int));
    
    if(bit_flags -> data == NULL)
    {
        free(bit_flags);
        return NULL;
    }
    
    return bit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
   if (hBit_flags == NULL || flag_position < 0)
   {
       return FAILURE;
   }
    
    int index = flag_position / int_size;
    int offset = flag_position % int_size;
    
    if(index >= hBit_flags -> capacity)
    {
        int new_capacity = index + 1;
        int* new_data = realloc(hBit_flags -> data, new_capacity * sizeof(int));
        
        if(new_data == NULL)
        {
            return FAILURE;
        }
        
        for(int i = hBit_flags -> capacity; i < new_capacity; ++i)
        {
            new_data[i] = 0;
        }
        
        hBit_flags -> data = new_data;
        hBit_flags -> capacity = new_capacity;
    }
    hBit_flags -> data[index] |= (1 << offset);
    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    if (hBit_flags == NULL || flag_position < 0)
    {
        return FAILURE;
    }
    
    int index = flag_position / int_size;
    int offset = flag_position % int_size;

    if (index >= hBit_flags -> capacity)
    {
        return FAILURE;
    }
    
    hBit_flags -> data[index] &= ~(1 << offset);
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    if (hBit_flags == NULL || flag_position < 0)
    {
        return -1;
    }
    
    int index = flag_position / int_size;
    int offset = flag_position % int_size;
    
    if (index >= hBit_flags -> capacity)
    {
        return -1;
    }
    
    return (hBit_flags -> data[index] >> offset) & 1;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    if (hBit_flags == NULL)
    {
        return -1;
    }
    
    return hBit_flags -> size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    if (hBit_flags == NULL)
    {
        return -1;
    }
    
    return hBit_flags -> capacity;

}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    if (phBit_flags == NULL || *phBit_flags == NULL)
    {
        return;
    }
    free((*phBit_flags) -> data);
    free(*phBit_flags);
    *phBit_flags = NULL;
    
}
