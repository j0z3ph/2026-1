/**
 * @file calloc_arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Arreglos con calloc
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
    printf("Usuario, ingresa el tamaño de tu arreglo: ");
    scanf("%i", &tamanio);

    arrg = (int *)calloc(tamanio, sizeof(int));

    for (int i = 0; i < tamanio; i++)
    {
        printf("%i ", *(arrg + i));
    }
    
    
    return 0;
}
