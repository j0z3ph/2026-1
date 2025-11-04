/**
 * @file arreglo_punteros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Creando arreglo de punteros
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
    int *arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = malloc(sizeof(int) * (i+2));
        *(arr[i]) = i+1;
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%p - %i\n", *(arr + i), *(*(arr + i)));
    }

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }

    return 0;
}
