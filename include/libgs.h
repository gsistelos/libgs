#ifndef LIBGS_H
#define LIBGS_H

#include <stddef.h>

void gs_matrix_free(void **matrix);
char **gs_split(const char *str, char delim);
char *gs_strjoin(const char *s1, const char *s2);

#endif // LIBGS_H
