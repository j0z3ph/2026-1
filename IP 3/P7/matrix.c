/**
 * @file matrix.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con arreglos bidimensionales
 * @version 0.1
 * @date 2025-09-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int matrix[3][3] = {{1, 2, 3},
                        {4, 4, 6},
                        {7, 8, 9}};
    int traspuesta[3][3];
    int determinante;

    /*for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("Ingrese el valor [%i, %i]: ", fila, columna);
            scanf("%i", &matrix[fila][columna]);
        }
    }*/

    // Imprime
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%i ", matrix[fila][columna]);
        }
        printf("\n");
    }

    // Determinante
    determinante = (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                   (matrix[1][0] * matrix[2][1] * matrix[0][2]) +
                   (matrix[2][0] * matrix[0][1] * matrix[1][2]) -
                   (matrix[2][0] * matrix[1][1] * matrix[0][2]) -
                   (matrix[0][0] * matrix[2][1] * matrix[1][2]) -
                   (matrix[1][0] * matrix[0][1] * matrix[2][2]);

    printf("%i\n", determinante);

    // Traspuesta
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            traspuesta[columna][fila] = matrix[fila][columna];
        }
    }

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%i ", traspuesta[fila][columna]);
        }
        printf("\n");
    }

    return 0;
}
