/**
 * @file referencias2.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Retorno de referencias
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
    int a = 100;
    int b = 6534;

    int *r = suma(a, b);

    printf("%p - %i\n", r, *r);
    
    return 0;
}
