/**
 * @file funciones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer funcion :>
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

// Declaraciones

/// @brief Suma dos numero enteros
/// @param a El primer numero
/// @param b El segundo numero
/// @return La suma de a y b
int suma(int a, int b);

int multiplica(int a, int b);

float divide(int dividendo, int divisor) {
    return (float)dividendo / (float)divisor;
}


int main()
{
    int numero1, numero2, efedex;
    printf("Usuario, ingresa dos numero enteros separados por comas (1,2): ");

    scanf("%i,%i", &numero1, &numero2);

    efedex = suma(numero1, numero2);

    printf("La suma es: %d\n", efedex);

    return 0;
}


// Definicion

int suma(int a, int b) {
    int sum = a + b;
    return sum;
}

int multiplica(int a, int b) {
    return a * b;
}