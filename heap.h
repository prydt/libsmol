#ifndef HEAP_H
#define HEAP_H

typedef struct max_heap
{
    int *keys;
    int len;
    int heap_size;
} max_heap;

int heap_right(int i);
int heap_left(int i);
int heap_parent(int i);

max_heap * init_max_heap(int len);
void free_max_heap(max_heap *h);

void build_max_heap(max_heap *h);
void max_heapify(max_heap *h, int index);

void heapsort(max_heap *h);

#endif
