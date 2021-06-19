#ifndef HEAP_H
#define HEAP_H

#include <stddef.h> /* for size_t */

/*
 * the max heap struct
 */
struct max_heap
{
    int *keys;
    size_t len;
    size_t heap_size;
};

/*
 * heap_right(int i)
 *  - returns index of the right child of the node at index i
 */
size_t heap_right(size_t i);

/*
 * heap_left(int i)
 *  - returns index of the left child of the node at index i
 */
size_t heap_left(size_t i);

/*
 * heap_parent(int i)
 *  - returns index of the parent of the node at index i
 */
size_t heap_parent(size_t i);

/*
 * init_max_heap(int len)
 *  - returns a pointer to a max_heap of size len
 */
struct max_heap * init_max_heap(size_t len);

/*
 * void free_max_heap(max_heap *h);
 *  - free the memory of max_heap h
 */
void free_max_heap(struct max_heap *h);

/*
 * build_max_heap(max_heap *h)
 *  - converts an unsorted h->keys into a valid property
 */
void build_max_heap(struct max_heap *h);

/*
 * max_heapify(max_heap *h, int index)
 *  - assumption: the children of i are valid max heaps
 *  - sifts index down if necessary to maintain the max heap property
 */
void max_heapify(struct max_heap *h, size_t i);

/*
 * heapsort(max_heap *h)
 *  - sorts h->keys into ascending order through the power of heaps!
 *
 *  asymptotic complexity: O(n lg n) where lg is log base 2
 *   - is in place!
 */
void heapsort(struct max_heap *h);

#endif
