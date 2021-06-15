#include <stdlib.h> /* for malloc and free */
#include <string.h> /* for memcpy */

void merge(int *A, int *L, int *R, int len, int len_l, int len_r)
{
    int cur = 0,
        cur_l = 0,
        cur_r = 0;

    while (cur_l < len_l && cur_r < len_r)
    {
        if (L[cur_l] < R[cur_r])
            A[cur++] = L[cur_l++];
        else
            A[cur++] = R[cur_r++];
    }

    for (; cur_l < len_l; cur_l++)
        A[cur++] = L[cur_l];

    for (; cur_r < len_r; cur_r++)
        A[cur++] = R[cur_r];
}

void merge_sort(int *A, int len)
{
    if (len == 1) /* base case */
        return;

    int mid = len / 2,
        len_l = mid,
        len_r = len - mid;

    int *L = (int*) malloc(sizeof(int) * len_l);
    int *R = (int*) malloc(sizeof(int) * len_r);
    memcpy(L, A, len_l);
    memcpy(R, A + mid + 1, len_r);

    merge_sort(L, len_l);
    merge_sort(R, len_r);
    merge(A, L, R, len, len_l, len_r);

    free(L);
    free(R);
}

