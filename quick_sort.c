#include <stdlib.h>
#include <stdio.h>

size_t partition(int *A, size_t p, size_t r)
{
    // TODO implement a better pseudo rng
    size_t rnd = p + (rand() % (r - p + 1));
    int t = A[r];
    A[r] = A[rnd];
    A[rnd] = t;

    int pivot = A[r];
    size_t i = p;
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

    return i;
}

void quick_sort_r(int *A, size_t p, size_t r)
{
    if (p < r)
    {
        size_t q = partition(A, p, r);

        /* casting to int because comparing a size_t and int
           causes the int to be converted into a size_t making
           making it the absolute value of what it used to be
           and in general this just causes a headache */

        if ((int)p < ((int)q) - 1)
            quick_sort_r(A, p, q - 1);

        if ((int)q + 1 < (int)r)
            quick_sort_r(A, q + 1, r);
    }
}

void quick_sort(int *A, size_t len)
{
    quick_sort_r(A, 0, len - 1);
}

