#include "libgs.h"

#include <criterion/criterion.h>

Test(gs_split_test, simple_input) {
    char **ret = gs_split("Hello world !", ' ');

    cr_assert_str_eq(ret[0], "Hello");
    cr_assert_str_eq(ret[1], "world");
    cr_assert_str_eq(ret[2], "!");

    cr_assert_null(ret[3]);
}

Test(gs_split_test, multiple_delim) {
    char **ret = gs_split("   Hello   world   !   ", ' ');

    cr_assert_str_eq(ret[0], "Hello");
    cr_assert_str_eq(ret[1], "world");
    cr_assert_str_eq(ret[2], "!");

    cr_assert_null(ret[3]);
}
