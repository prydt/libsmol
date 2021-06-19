#include "heap.h"
#include <stdlib.h> /* for malloc and free */

size_t heap_right(size_t i)
{
    return (2*i)+1;
}

size_t heap_left(size_t i)
{
    return (2*i)+2;
}

size_t heap_parent(size_t i)
{
    return (i-1)/2;
}

struct max_heap * init_max_heap(size_t len)
{
    struct max_heap *h = malloc(sizeof *h);
    h->keys = malloc(sizeof(int) * len);
    h->len = len;
    h->heap_size = len;
    return h;
}

void free_max_heap(struct max_heap *h)
{
    free(h->keys);
    free(h);
}


void build_max_heap(struct max_heap *h)
{
    for (int i = h->len / 2; i >= 0; i--)
        max_heapify(h, i);
}

void max_heapify(struct max_heap *h, size_t i)
{
    int l = heap_left(i);
    int r = heap_right(i);
    int largest;

    if (l < h->heap_size && h->keys[l] > h->keys[i])
        largest = l;
    else
        largest = i;

    if (r < h->heap_size && h->keys[r] > h->keys[largest])
        largest = r;

    if (largest != i)
    {
        int t = h->keys[i];
        h->keys[i] = h->keys[largest];
        h->keys[largest] = t;

        max_heapify(h, largest);
    }
}

void heapsort(struct max_heap *h)
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
