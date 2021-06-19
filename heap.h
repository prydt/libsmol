#ifndef HEAP_H
#define HEAP_H

/*
 * the max heap struct
 */
typedef struct max_heap
{
    int *keys;
    int len;
    int heap_size;
} max_heap;

/*
 * heap_right(int i)
 *  - returns index of the right child of the node at index i
 */
int heap_right(int i);

/*
 * heap_left(int i)
 *  - returns index of the left child of the node at index i
 */
int heap_left(int i);

/*
 * heap_parent(int i)
 *  - returns index of the parent of the node at index i
 */

int heap_parent(int i);

/*
 * init_max_heap(int len)
 *  - returns a pointer to a max_heap of size len
 */
max_heap * init_max_heap(int len);

/*
 * void free_max_heap(max_heap *h);
 *  - free the memory of max_heap h
 */
void free_max_heap(max_heap *h);

/*
 * build_max_heap(max_heap *h)
 *  - converts an unsorted h->keys into a valid property
 */
void build_max_heap(max_heap *h);

/*
 * max_heapify(max_heap *h, int index)
 *  - assumption: the children of index are valid max heaps
 *  - sifts index down if necessary to maintain the max heap property
 */
void max_heapify(max_heap *h, int index);

/*
 * heapsort(max_heap *h)
 *  - sorts h->keys into ascending order through the power of heaps!
 *
 *  asymptotic complexity: O(n lg n) where lg is log base 2
 *   - is in place!
 */
void heapsort(max_heap *h);

#endif
