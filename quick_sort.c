#include <stdlib.h> /* for size_t and rand() */

size_t partition(int *A, size_t low, size_t high)
{
    size_t rnd = low + (rand() % (high - low + 1));
    int temp = A[high];
    A[high] = A[rnd];
    A[rnd] = temp;

    int pivot = A[high];
    size_t less_index = low;
    for (int i = low; i < high; i++)
    {
        if (A[i] < pivot)
        {
            temp = A[less_index];
            A[less_index] = A[i];
            A[i] = temp;

            less_index++;
        }
    }

    temp = A[less_index];
    A[less_index] = A[high];
    A[high] = temp;

    return less_index;
}

void quick_sort_r(int *A, size_t low, size_t high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);

        /*
         * casting low and high to ints for proper comparisons
         *
         * comparing an int to a size_t has caused issues since
         * the int is converted to a size_t, making negative values
         * positive instead and causing quite the headache
         */
        if ((int)low < pivot - 1)
            quick_sort_r(A, low, pivot - 1);
        if (pivot + 1 < (int)high)
            quick_sort_r(A, pivot + 1, high);
    }
}

void quick_sort(int *A, size_t len)
{
    quick_sort_r(A, 0, len - 1);
}
