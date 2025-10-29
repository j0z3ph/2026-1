/**
 * @file calloc_arr.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Ejemplo de calloc 
 * @version 0.1
 * @date 2025-10-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arrg;
    int tamanio;

    printf("Usuario, ingresa el tamanio del arreglo que deseas: ");
    scanf("%d", &tamanio);

    arrg = (int *)calloc(tamanio, sizeof(int));

    for (int i = 0; i < tamanio; i++)
    {
        printf("%i ", *(arrg + i));
    }
    
    return 0;
}
