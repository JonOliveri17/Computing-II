#ifndef number_filter_h
#define number_filter_h

struct array
{
    int size;
    int capacity;
    int* data;
};

typedef struct array Array;

typedef void* ARRAY;

void array_insert(ARRAY hTemp, int item);

void array_filter(ARRAY hTemp);

void array_destroy(ARRAY* phTemp);

ARRAY array_init_default(void);

int array_size(ARRAY hTemp);

int array_capacity(ARRAY hTemp);

int* location(ARRAY hTemp, int index);

void swap(int* a, int* b);

void bubble_sort(ARRAY hTemp, int size);



#endif /* number_filter_h */
