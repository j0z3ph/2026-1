/**
 * @file funciones1.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Punteros y funciones?
 * @version 0.1
 * @date 2025-10-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int* suma(int a, int b) {
    int c = a + b;
    return &c;
}

int main()
{
    int a = 7, b = 1000;
    int *r = suma(a,b);
    
    printf("%i\n", *r);
    return 0;
}
