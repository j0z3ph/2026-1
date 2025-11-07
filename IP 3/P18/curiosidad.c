/**
 * @file curiosidad.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Curiosidades
 * @version 0.1
 * @date 2025-11-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int suma(int a, int b) {
    return a + b;
}

int main()
{
    int arr[8];
    int (*pt)[8] = &arr;


    int (*funcion)(int, int) = &suma;
    printf("%p - %p - %i\n", suma, funcion, funcion(4,5));

    
    return 0;
}
