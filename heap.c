#include "heap.h"
#include <stdlib.h> /* for malloc and free */

int heap_right(int i)
{
    return (2*i)+1;
}

int heap_left(int i)
{
    return (2*i)+2;
}

int heap_parent(int i)
{
    return (i-1)/2;
}

max_heap * init_max_heap(int len)
{
    max_heap *h = (max_heap*) malloc(sizeof(max_heap));
    h->keys = (int*) malloc(sizeof(int) * len);
    h->len = len;
    h->heap_size = len;
    return h;
}

void free_max_heap(max_heap *h)
{
    free(h->keys);
    free(h);
}


void build_max_heap(max_heap *h)
{
    for (int i = h->len / 2; i >= 0; i--)
        max_heapify(h, i);
}

void max_heapify(max_heap *h, int index)
{
    int l = heap_left(index);
    int r = heap_right(index);
    int largest;

    if (l < h->heap_size && h->keys[l] > h->keys[index])
        largest = l;
    else
        largest = index;

    if (r < h->heap_size && h->keys[r] > h->keys[largest])
        largest = r;

    if (largest != index)
    {
        int t = h->keys[index];
        h->keys[index] = h->keys[largest];
        h->keys[largest] = t;

        max_heapify(h, largest);
    }
}

void heapsort(max_heap *h)
{
    build_max_heap(h);
    for (int i = h->len - 1; i > 0; i--)
    {
        int t = h->keys[0];
        h->keys[0] = h->keys[i];
        h->keys[i] = t;

        h->heap_size--;
        max_heapify(h, 0);
    }
}
