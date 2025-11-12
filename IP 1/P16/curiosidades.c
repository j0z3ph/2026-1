/**
 * @file curiosidades.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Curiosidades
 * @version 0.1
 * @date 2025-11-11
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
    int (*la_suma_rara)(int, int) = suma;

    printf("La suma es: %i\n", la_suma_rara(3,4));
    
    return 0;
}
