/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que imprime un arreglo
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

void imprimir(int arrg[], int size) {
    static int i = 0;
    if ( i < size)
    {
        printf("%i ", arrg[i]);
        i++;
        imprimir(arrg, size);
    }
}

int main()
{
    int arrg[10] = {1,2,3,4,5,6,7,8,9,0 };

    imprimir(arrg, 10);
    
    return 0;
}
