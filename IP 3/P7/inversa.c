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

int main()
{
    int matrix[3][3] = {{0, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int traspuesta[3][3];
    int adjunta[3][3];
    float inversa[3][3];
    int determinante;
    float factor;

    // Paso 0: Imprimimos la matriz original
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%i ", matrix[fila][columna]);
        }
        printf("\n");
    }

    // Paso 1
    // Calculamos el determinante
    // Determinante
    determinante = (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                   (matrix[1][0] * matrix[2][1] * matrix[0][2]) +
                   (matrix[2][0] * matrix[0][1] * matrix[1][2]) -
                   (matrix[2][0] * matrix[1][1] * matrix[0][2]) -
                   (matrix[0][0] * matrix[2][1] * matrix[1][2]) -
                   (matrix[1][0] * matrix[0][1] * matrix[2][2]);

    // Paso 2: Validamos que no sea cero
    if (determinante == 0)
    {
        printf("Su matriz no tiene inversa :C\n");
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
    adjunta[0][0] = +1 * (traspuesta[1][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[1][2]);
    adjunta[0][1] = -1 * (traspuesta[1][0] * traspuesta[2][2] - traspuesta[1][2] * traspuesta[2][0]);
    adjunta[0][2] = +1 * (traspuesta[1][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[1][1]);
    adjunta[1][0] = -1 * (traspuesta[0][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[0][2]);
    adjunta[1][1] = +1 * (traspuesta[0][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[0][2]);
    adjunta[1][2] = -1 * (traspuesta[0][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[0][1]);
    adjunta[2][0] = +1 * (traspuesta[0][1] * traspuesta[1][2] - traspuesta[1][1] * traspuesta[0][2]);
    adjunta[2][1] = -1 * (traspuesta[0][0] * traspuesta[1][2] - traspuesta[1][0] * traspuesta[0][2]);
    adjunta[2][2] = +1 * (traspuesta[1][1] * traspuesta[0][0] - traspuesta[1][0] * traspuesta[0][1]);

    // Paso 6: Calculamos la inversa
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            inversa[fila][columna] = factor * adjunta[fila][columna];
        }
    }

    // Paso 7: Imprimimos el resultado
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%f ", inversa[fila][columna]);
        }
        printf("\n");
    }


    return 0;
}
