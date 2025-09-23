/**
 * @file matrix.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con matrices
 * @version 0.1
 * @date 2025-09-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int matrix[3][3] = {{1,2,3}, 
                        {4,5,6}, 
                        {7,8,9}};
    int transpuesta[3][3];
    int adjunta[3][3];

    int determinante;

    /*for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("Ingrese el valor de la posicion [%i, %i]: ", fila, columna);
            scanf("%i", &matrix[fila][columna]);
        } 
    }*/


    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%d ", matrix[fila][columna]);
        }
        printf("\n");    
    }


    // Calcular el determinante

    determinante = (matrix[0][0]*matrix[1][1]*matrix[2][2])+
                   (matrix[1][0]*matrix[2][1]*matrix[0][2])+
                   (matrix[2][0]*matrix[0][1]*matrix[1][2])-
                   (matrix[2][0]*matrix[1][1]*matrix[0][2])-
                   (matrix[0][0]*matrix[2][1]*matrix[1][2])-
                   (matrix[1][0]*matrix[0][1]*matrix[2][2]);

    printf("%i\n", determinante);

    if(determinante == 0) {
        printf("Upsssss, no tiene inversa T~T\n");
        return 1;
    }


    // Transpuesta
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            transpuesta[columna][fila] = matrix[fila][columna];   
        }
    }

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%d ", transpuesta[fila][columna]);
        }
        printf("\n");    
    }

    // Adjunta
    adjunta[0][0] = +1 *(matrix[1][1]*matrix[2][2] - matrix[2][1]*matrix[1][2]);
    adjunta[0][1] = -1 *(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]);
    adjunta[0][2] = +1 *(matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1]);
    adjunta[1][0] = -1 *(matrix[0][1]*matrix[2][2] - matrix[2][1]*matrix[0][2]);
    adjunta[1][1] = +1 *(matrix[0][0]*matrix[2][2] - matrix[2][0]*matrix[0][2]);
    adjunta[1][2] = -1 *(matrix[0][0]*matrix[2][1] - matrix[2][0]*matrix[0][1]);
    adjunta[2][0] = +1 *(matrix[0][1]*matrix[1][2] - matrix[0][2]*matrix[1][1]);
    adjunta[2][1] = -1 *(matrix[0][0]*matrix[1][2] - matrix[0][2]*matrix[1][0]);
    adjunta[2][2] = +1 *(matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);

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
