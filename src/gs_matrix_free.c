#include <stdlib.h>

/*
 * @brief Free a matrix of pointers
 * @param matrix The matrix to free
 **/
void gs_matrix_free(void **matrix) {
    if (matrix == NULL)
        return;

    for (size_t i = 0; matrix[i]; i++)
        free(matrix[i]);
    free(matrix);
}
