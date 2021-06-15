#include <stdlib.h>
#include <check.h>

#include "../sort.h"

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



Suite * testing_suite()
{
    Suite *s;
    s = suite_create("libsmol");

    TCase *sort_case;
    sort_case = tcase_create("sort.h");

    tcase_add_test(sort_case, insertion_sort_test);
    tcase_add_test(sort_case, merge_sort_test);

    suite_add_tcase(s, sort_case);

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
