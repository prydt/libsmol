#include <stdlib.h>
#include <stdio.h>

size_t partition(int *A, size_t p, size_t r)
{
    size_t rnd = p + (rand() % (r - p + 1)); // TODO implement a better pseudo rng

    int t = A[r];
    A[r] = A[rnd];
    A[rnd] = t;



    /* printf("partition: p=%d, r=%d\n", p,r); */

    int pivot = A[r];
    //printf("pivot = %d\n", pivot);
    size_t i = p;
    /* printf("partition: i=%d\n",i); */
    for (int j = p; j < r; j++)
    {
        if (A[j] < pivot)
        {
            t = A[i];
            A[i] = A[j];
            A[j] = t;

            i++;
        }
    }

    t = A[i];
    A[i] = A[r];
    A[r] = t;

    /* printf("returning i = %d\n", i); */
    return i;
}

void quick_sort_r(int *A, size_t p, size_t r)
{
    /* printf("p=%d, r=%d\n",p,r); */
    if (p < r)
    {
        size_t q = partition(A, p, r);
        /* printf("q=%d\n",q); */

        /* printf("nnnnnn p=%d, r=%d\n",p,q-1); */
        /* printf("nnnnnn p=%d, r=%d\n",q+1,r); */

        if ((int)p < ((int)q) - 1)
        {
            /* printf("got here\n"); */
            quick_sort_r(A, p, q - 1);
        }
        if (q + 1 < r)
            quick_sort_r(A, q + 1, r);
    }
}

void quick_sort(int *A, size_t len)
{
    /* printf("len=%d\n", len); */
    quick_sort_r(A, 0, len - 1);
}


