/**
 * @file ptr_arreglo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Creando punteros a arreglos
 * @version 0.1
 * @date 2025-11-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int (*m)[3];
    int cont = 1;

    m = malloc(sizeof(int) * 9);

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            *(*(m+fila) + columna) = cont++;
        }
        
    }

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%i ", *(*(m+fila) + columna));
        }
        printf("\n");
    }
    
    
    return 0;
}

