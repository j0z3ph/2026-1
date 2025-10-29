/**
 * @file malloc.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer memoria dinamica
 * @version 0.1
 * @date 2025-10-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *entero = (int *)malloc(4);
    *entero = 5;

    printf("%p - %p - %i\n", &entero, entero, *entero);
    
    return 0;
}
