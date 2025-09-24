/**
 * @file matriz.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con arreglos de dos dimensiones
 * @version 0.1
 * @date 2025-09-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("Ingrese el valor de la posicion [%i, %i]: ", fila, columna);
            scanf("%i", &matrix[fila][columna]);
        }
        
    }


    // Imprimo
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%d ", matrix[fila][columna]);
        }
        printf("\n");
    }
    

    return 0;
}
