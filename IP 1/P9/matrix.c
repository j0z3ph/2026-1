/**
 * @file matrix.c 
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Codigo de la biblioteca matrix.
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdbool.h>
#include<stdio.h>

/// @brief Calcula el determinante de cualquier matriz de 3x3
/// @param matrix La matriz
/// @return El determinante
int determinante(int matrix[3][3]) {
    int det = (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                   (matrix[1][0] * matrix[2][1] * matrix[0][2]) +
                   (matrix[2][0] * matrix[0][1] * matrix[1][2]) -
                   (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
                   (matrix[1][2] * matrix[2][1] * matrix[0][0]) -
                   (matrix[2][2] * matrix[0][1] * matrix[1][0]);
    return det;
}

/// @brief Calcula la traspuesta de cualquier matriz de 3x3
/// @param matrix La matriz
/// @param tras La traspuesta
void traspuesta(int matrix[3][3], int tras[3][3]) {
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            tras[columna][fila] = matrix[fila][columna];
        }
    }
}

void adjunta(int matrix[3][3], int adj[3][3]) {
    adj[0][0] = +1 * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    adj[0][1] = -1 * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    adj[0][2] = +1 * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    adj[1][0] = -1 * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    adj[1][1] = +1 * (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]);
    adj[1][2] = -1 * (matrix[2][1] * matrix[0][0] - matrix[2][0] * matrix[0][1]);
    adj[2][0] = +1 * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
    adj[2][1] = -1 * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    adj[2][2] = +1 * (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

bool inversa(int matrix[3][3], float inv[3][3]) {
    int det;
    int tras[3][3];
    int adj[3][3];
    float factor;

    // Paso 1: Obtenemos el determinante
    det = determinante(matrix);

    // Paso 2: Validamos el determinante
    if (det == 0)
    {
        printf("Esta matriz no tiene inversa ToT\n");
        return false;
    }

    // Paso 3: Calculamos el factor
    factor = 1.0f / (float)det;

    // Paso 4: Calculamos la traspuesta
    traspuesta(matrix, tras);

    // Paso 5: Calculamos la adjunta de la traspuesta
    adjunta(tras, adj);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inv[i][j] = factor * adj[i][j];
        }
    }

    return true;
}

void imprime(float matrix[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

