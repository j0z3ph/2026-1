/**
 * @file matrices.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi segunda bibliotecas de funciones
 * @version 0.1
 * @date 2025-10-13 
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdbool.h>

/// @brief Calcula el determinante de una matrix de 3x3
/// @param matrix La matrix
/// @return El determinante
int determinante(int matrix[3][3])
{
    // Calculamos el determinante
    // Determinante
    int det = (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
              (matrix[1][0] * matrix[2][1] * matrix[0][2]) +
              (matrix[2][0] * matrix[0][1] * matrix[1][2]) -
              (matrix[2][0] * matrix[1][1] * matrix[0][2]) -
              (matrix[0][0] * matrix[2][1] * matrix[1][2]) -
              (matrix[1][0] * matrix[0][1] * matrix[2][2]);
    return det;
}

/// @brief Calcula la traspuesta de una matrix de 3x3
/// @param matrix La matrix
/// @param tras La traspuesta
void traspuesta(int matrix[3][3], int tras[3][3])
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            tras[columna][fila] = matrix[fila][columna];
        }
    }
}

/// @brief Calcula la adjunta de una matrix de 3x3
/// @param matrix La matrix
/// @param adj La adjunta
void adjunta(int matrix[3][3], int adj[3][3])
{
    adj[0][0] = +1 * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    adj[0][1] = -1 * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    adj[0][2] = +1 * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    adj[1][0] = -1 * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    adj[1][1] = +1 * (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]);
    adj[1][2] = -1 * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);
    adj[2][0] = +1 * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
    adj[2][1] = -1 * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    adj[2][2] = +1 * (matrix[1][1] * matrix[0][0] - matrix[1][0] * matrix[0][1]);
}

/// @brief Calcula la inversa de una matriz de 3x3
/// @param matrix La matriz
/// @param inv La inversa
/// @return True si se pudo calcular. False si no tiene inversa.
bool inversa(int matrix[3][3], float inv[3][3])
{
    int tras[3][3];
    int adj[3][3];
    int det;
    float factor;

    // Paso 1
    // Calculamos el determinante
    // Determinante
    det = determinante(matrix);

    // Paso 2: Validamos que no sea cero
    if (det == 0)
    {
        printf("Su matriz no tiene inversa :C\n");
        return false;
    }

    // Paso 3: Calculamos el factor
    factor = 1.0f / (float)det;

    // Paso 4: Calculamos la traspuesta
    traspuesta(matrix, tras);

    // Paso 5: Calculamos la adjunta de la traspuesta
    adjunta(tras, adj);

    // Paso 6: Calculamos la inversa
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            inv[fila][columna] = factor * adj[fila][columna];
        }
    }

    return true;
}
