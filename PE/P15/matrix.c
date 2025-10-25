/**
 * @file matrix.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Punteros y matrices
 * @version 0.1
 * @date 2025-10-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 9; i++)
    {
        // printf("%p - %i\n", *matrix + i, *(*matrix + i));
        if (i % 3 == 0) printf("\n");

        printf("%i ", *(*matrix + i));
    }

    return 0;
}
