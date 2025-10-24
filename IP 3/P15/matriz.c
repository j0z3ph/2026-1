/**
 * @file matriz.c
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
    int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // printf("%p - %i\n", *(m+1)+1, *(*(m+1)+1));

    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            printf("\n");
        }
        printf("%i ", *(*m + i));
    }

    return 0;
}
