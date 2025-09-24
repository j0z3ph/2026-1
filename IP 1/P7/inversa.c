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
#include<stdio.h>

int main()
{
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int determinante;
    int traspuesta[3][3];
    int adjunta[3][3];
    

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%d ", matrix[fila][columna]);
        }
        printf("\n");
    }

    // Determinante
    determinante = (matrix[0][0]*matrix[1][1]*matrix[2][2])+
                   (matrix[1][0]*matrix[2][1]*matrix[0][2])+
                   (matrix[2][0]*matrix[0][1]*matrix[1][2])-
                   (matrix[0][2]*matrix[1][1]*matrix[2][0])-
                   (matrix[1][2]*matrix[2][1]*matrix[0][0])-
                   (matrix[2][2]*matrix[0][1]*matrix[1][0]);
    
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
            printf("%d ", traspuesta[fila][columna]);
        }
        printf("\n");
    }

    // Adjunta
    adjunta[0][0] = +1*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]);
    adjunta[0][1] = -1*(matrix[1][0]*matrix[2][2] - matrix[2][0]*matrix[1][2]);
    adjunta[0][2] = +1*(matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1]);
    adjunta[1][0] = -1*(matrix[0][1]*matrix[2][2] - matrix[2][1]*matrix[0][2]);
    adjunta[1][1] = +1*(matrix[0][0]*matrix[2][2] - matrix[2][0]*matrix[0][2]);
    adjunta[1][2] = -1*(matrix[2][1]*matrix[0][0] - matrix[2][0]*matrix[0][1]);
    adjunta[2][0] = +1*(matrix[0][1]*matrix[1][2] - matrix[1][1]*matrix[0][2]);
    adjunta[2][1] = -1*(matrix[0][0]*matrix[1][2] - matrix[1][0]*matrix[0][2]);
    adjunta[2][2] = +1*(matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%d ", adjunta[fila][columna]);
        }
        printf("\n");
    }

    return 0;
}
