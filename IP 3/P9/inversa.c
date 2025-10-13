/**
 * @file inversa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que calcula la inversa de una matriz de 3x3
 * @version 0.1
 * @date 2025-09-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include "matrices.h"

int main()
{
    int matrix[3][3] = {{0, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    float inv[3][3];

    if (inversa(matrix, inv))
    {
        // Paso 7: Imprimimos el resultado
        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                printf("%f ", inv[fila][columna]);
            }
            printf("\n");
        }
    }

    return 0;
}
