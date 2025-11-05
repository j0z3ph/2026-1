/**
 * @file arreglo_ptr.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Creando arreglo de punteros
 * @version 0.1
 * @date 2025-11-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arrg[10];

    for (int i = 0; i < 10; i++)
    {
        arrg[i] = (int *)malloc(sizeof(int) * (i + 2));
        *(arrg[i]) = i+1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%p - %i\n", arrg[i], *(arrg[i]));
    }
    
    for (int i = 0; i < 10; i++)
    {
        free(arrg[i]);
    }


    return 0;
}
