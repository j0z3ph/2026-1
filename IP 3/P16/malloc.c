/**
 * @file malloc.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer reservación de memoria dinámica :>
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
    int *entero;

    entero = (int *)malloc(4); // Ya reservamos 4 bytes de memoria en el HEAP

    *entero = 10;

    printf("%p - %p - %i\n", &entero, entero, *entero);
    
    return 0;
}
