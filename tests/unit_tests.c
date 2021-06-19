#include <stdlib.h>
#include <check.h>

#include "../sort.h"
#include "../heap.h"

START_TEST(insertion_sort_test)
{
    int a[10] = {3,2,1,5,7,2,9,10,5,6};
    int b[10] = {8,5,1,6,7,10,6,2,3,4};
    int c[10] = {10,9,8,7,6,5,4,3,2,1};
    int len = 10;

    insertion_sort(a, len);
    insertion_sort(b, len);
    insertion_sort(c, len);

    for (int i = 1; i < len; i++)
    {
        ck_assert_int_le(a[i-1], a[i]); /* ASSERT a[i-1] <= a[i] */
        ck_assert_int_le(b[i-1], b[i]);
        ck_assert_int_le(c[i-1], c[i]);
    }
}
END_TEST

START_TEST(merge_sort_test)
{
    int a[10] = {3,2,1,5,7,2,9,10,5,6};
    int b[10] = {8,5,1,6,7,10,6,2,3,4};
    int c[10] = {10,9,8,7,6,5,4,3,2,1};
    int len = 10;

    merge_sort(a, len);
    merge_sort(b, len);
    merge_sort(c, len);

    for (int i = 1; i < len; i++)
    {
        ck_assert_int_le(a[i-1], a[i]); /* ASSERT a[i-1] <= a[i] */
        ck_assert_int_le(b[i-1], b[i]);
        ck_assert_int_le(c[i-1], c[i]);
    }
}
END_TEST

START_TEST(init_max_heap_test)
{
    int len = 10;
    max_heap *h = init_max_heap(len);
    ck_assert_int_eq(h->len, len);
    ck_assert_int_eq(h->heap_size, len);
    ck_assert_ptr_nonnull(h->keys);
    free_max_heap(h);
}
END_TEST

START_TEST(build_max_heap_test)
{
    int len = 10;
    max_heap *h = init_max_heap(len);
    h->keys[0] = 2;
    h->keys[1] = 3;
    h->keys[2] = 1;
    h->keys[3] = 6;
    h->keys[4] = 5;
    h->keys[5] = 7;
    h->keys[6] = 8;
    h->keys[7] = 9;
    h->keys[8] = 1;
    h->keys[9] = 6;

    build_max_heap(h);

    for (int i = 0; i < h->heap_size; i++)
    {
        int r = heap_right(i);
        int l = heap_left(i);
        if (r < h->heap_size)
            ck_assert_int_ge(h->keys[i], h->keys[r]);
        if (l < h->heap_size)
            ck_assert_int_ge(h->keys[i], h->keys[l]);
    }

    free_max_heap(h);
}
END_TEST

START_TEST(heapsort_test)
{
    int len = 10;
    max_heap *h = init_max_heap(len);
    h->keys[0] = 2;
    h->keys[1] = 3;
    h->keys[2] = 1;
    h->keys[3] = 6;
    h->keys[4] = 5;
    h->keys[5] = 7;
    h->keys[6] = 8;
    h->keys[7] = 9;
    h->keys[8] = 1;
    h->keys[9] = 6;

    heapsort(h);

    for (int i = 1; i < len; i++)
    {
        ck_assert_int_le(h->keys[i-1], h->keys[i]); /* ASSERT a[i-1] <= a[i] */
    }

    free_max_heap(h);
}
END_TEST


Suite * testing_suite()
{
    Suite *s;
    s = suite_create("libsmol");

    TCase *sort_case, *heap_case;
    sort_case = tcase_create("sort.h");
    heap_case = tcase_create("heap.h");

    tcase_add_test(sort_case, insertion_sort_test);
    tcase_add_test(sort_case, merge_sort_test);

    tcase_add_test(heap_case, init_max_heap_test);
    tcase_add_test(heap_case, build_max_heap_test);
    tcase_add_test(heap_case, heapsort_test);

    suite_add_tcase(s, sort_case);
    suite_add_tcase(s, heap_case);

    return s;
}

int main()
{
    int failed;
    Suite *s;
    SRunner *sr;

    s = testing_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
