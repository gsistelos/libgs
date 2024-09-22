#include "libgs.h"

#include <stdlib.h>
#include <string.h>

static size_t substrings(const char *str, char delim) {
    size_t size = 0;

    while (*str) {
        if (*str == delim)
            str++;
        else {
            str = strchrnul(str, delim);
            size++;
        }
    }

    return size;
}

/*
 * @brief Split a string into an array of strings
 * @param str The string to split
 * @param delim The delimiters to split the string with
 * @return The array of strings
 **/
char **gs_split(const char *str, char delim) {
    size_t size = substrings(str, delim);

    char **split = malloc(sizeof(char *) * (size + 1));
    if (split == NULL)
        return NULL;

    for (size_t i = 0; i < size; i++) {
        while (*str && *str == delim)
            str++;

        size_t len = 0;
        while (str[len] && str[len] != delim)
            len++;

        split[i] = strndup(str, len);
        if (split[i] == NULL) {
            gs_matrix_free((void **)split);
            return NULL;
        }

        str += len + 1;
    }

    split[size] = NULL;

    return split;
}
