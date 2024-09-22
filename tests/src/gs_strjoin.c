#include "libgs.h"

#include <criterion/criterion.h>

Test(gs_strjoin_test, simple_input) {
    char *ret = gs_strjoin("Hello, ", "world!");

    cr_assert_str_eq(ret, "Hello, world!");
}

Test(gs_strjoin_test, null) {
    char *ret;

    ret = gs_strjoin("Hello, world!", NULL);
    cr_assert_str_eq(ret, "Hello, world!");

    ret = gs_strjoin(NULL, "Hello, world!");
    cr_assert_str_eq(ret, "Hello, world!");
}
