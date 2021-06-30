#ifndef SORT_H
#define SORT_H

/*
 * insertion_sort(int *A, int len)
 *  - perform insertion sort on array A of length len
 *
 *  asymptotic complexity: O(n^2)
 *
 */
void insertion_sort(int *A, int len);

/*
 * merge_sort(int *A, int len)
 *  - perform merge sort on an array A of length len
 *
 *  asymptotic complexity: O(n lg n) where lg is log base 2
 *
 *  downsides: uses space for temporary arrays
 *
 */
void merge_sort(int *A, int len);

/*
 * quick_sort(int *A, int len)
 *  - perform quick sort on an array A of length len
 *
 * asymptotic complexity:
 *  - worst case performance is O(n^2) but this is
 *    exceptionally uncommon
 *  - average case performance is O(n lg n) which is
 *    which important given the use of a randomized
 *    paritioning subroutine
 */
void quick_sort(int *A, int len);

#endif
