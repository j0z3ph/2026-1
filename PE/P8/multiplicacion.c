/**
 * @file multiplicacion.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que calcula la multiplicacion de dos matrices
 * @version 0.1
 * @date 2025-09-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int matrixA[2][3] = {{2,5,8},
                         {3,9,14}};
    int matrixB[3][1] = {{4},{2},{5}};
    int matrixR[2][1];
    int sumatoria = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            sumatoria = 0;
            for (int k = 0; k < 3; k++)
            {
                sumatoria += matrixA[i][k]*matrixB[k][j];
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
