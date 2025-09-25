/**
 * @file multiplicacion.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Multiplicaciones de matrices
 * @version 0.1
 * @date 2025-09-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int matrixA[2][3] = {{4,5,6},{14,15,16}};
    int matrixB[3][1] = {{2},{4},{6}};
    int matrixR[2][1];
    int sumatoria = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            sumatoria = 0;
            for (int k = 0; k < 3; k++)
            {
                sumatoria += matrixA[i][k] * matrixB[k][j];
            }
            matrixR[i][j] = sumatoria;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%i ", matrixR[i][j]);
        }
        printf("\n");
    }

    
    

    return 0;
}
