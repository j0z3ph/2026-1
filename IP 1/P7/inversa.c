/**
 * @file inversa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que determina la inversa de una matriz
 * @version 0.1
 * @date 2025-09-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 8}, {7, 8, 9}};
    int determinante;
    int traspuesta[3][3];
    int adjunta[3][3];
    float inversa[3][3];
    float factor;

    // Paso 0: Imprimo la matriz original
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%d ", matrix[fila][columna]);
        }
        printf("\n");
    }

    // Paso 1: Obtenemos el determinante
    determinante = (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                   (matrix[1][0] * matrix[2][1] * matrix[0][2]) +
                   (matrix[2][0] * matrix[0][1] * matrix[1][2]) -
                   (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
                   (matrix[1][2] * matrix[2][1] * matrix[0][0]) -
                   (matrix[2][2] * matrix[0][1] * matrix[1][0]);

    // Paso 2: Validamos el determinante
    if (determinante == 0)
    {
        printf("Esta matriz no tiene inversa ToT\n");
        return 1;
    }

    // Paso 3: Calculamos el factor
    factor = 1.0f / (float)determinante;

    // Paso 4: Calculamos la traspuesta
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            traspuesta[columna][fila] = matrix[fila][columna];
        }
    }

    // Paso 5: Calculamos la adjunta de la traspuesta
    adjunta[0][0] = +1 * (traspuesta[1][1] * traspuesta[2][2] - traspuesta[1][2] * traspuesta[2][1]);
    adjunta[0][1] = -1 * (traspuesta[1][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[1][2]);
    adjunta[0][2] = +1 * (traspuesta[1][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[1][1]);
    adjunta[1][0] = -1 * (traspuesta[0][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[0][2]);
    adjunta[1][1] = +1 * (traspuesta[0][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[0][2]);
    adjunta[1][2] = -1 * (traspuesta[2][1] * traspuesta[0][0] - traspuesta[2][0] * traspuesta[0][1]);
    adjunta[2][0] = +1 * (traspuesta[0][1] * traspuesta[1][2] - traspuesta[1][1] * traspuesta[0][2]);
    adjunta[2][1] = -1 * (traspuesta[0][0] * traspuesta[1][2] - traspuesta[1][0] * traspuesta[0][2]);
    adjunta[2][2] = +1 * (traspuesta[0][0] * traspuesta[1][1] - traspuesta[0][1] * traspuesta[1][0]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inversa[i][j] = factor * adjunta[i][j];
        }
    }

    // Paso 6: Imprimimos el resultado
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", inversa[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
