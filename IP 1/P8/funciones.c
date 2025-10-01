/**
 * @file funciones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer funcion :>
 * @version 0.1
 * @date 2025-09-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

// Declaraciones

/// @brief Suma dos numero enteros
/// @param a El primer entero a sumar
/// @param b El segunod entero a sumar
/// @return La suma de a + b
int suma(int a, int b);

/// @brief Multiplica dos numero
/// @param a Primer numero
/// @param b Segundo numero
/// @return La multipicacion
int multiplica(int a, int b);

float division(int dividendo, int divisor) {
    return (float)dividendo / (float)divisor;
}

int main()
{
    
    printf("%i\n", suma(8,17));
    printf("%i\n", suma(8,17));
    printf("%i\n", suma(8,17));
    printf("%i\n", suma(8,17));
    printf("%i\n", multiplica(8,17));
    printf("%i\n", multiplica(8,17));
    printf("%i\n", multiplica(8,17));
    printf("%i\n", multiplica(8,17));
    
    return 0;
}

// Definiciones

int suma(int a, int b) {
    int resultado;
    resultado = a + b;
    return resultado;
}

int multiplica(int a, int b) {
    return a * b;
}