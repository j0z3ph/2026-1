/**
 * @file punteros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer puntero XD
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int entero = 1;
    int *puntero = &entero;

    printf("%p - %p - %i\n", puntero, &entero, *puntero);
    
    return 0;
}
