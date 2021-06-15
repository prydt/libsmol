void insertion_sort(int *A, int len)
{
    for (int i = 1; i < len; i++)
        for (int j = i; j > 0 && A[j] < A[j-1]; j--)
        {
            int t = A[j];
            A[j] = A[j-1];
            A[j-1] = t;
        }
}
