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
#include <stdio.h>

// Declaracion de funciones

/// @brief Suma dos numeros enteros
/// @param a El primer numero a sumar
/// @param b El segundo numero a sumar
/// @return La suma de los dos numeros proporcionados.
int suma(int a, int b);

/// @brief Multiplica dos numero enteros
/// @param a El primer entero
/// @param b El segundo entero
/// @return La multiplicacion de a * b
int multiplicacion(int a, int b);

/// @brief Divide
/// @param dividendo Pues dividendo
/// @param divisor Pues divisor
/// @return La division
float division(int dividendo, int divisor) {
    return (float)dividendo / (float)divisor;
}

int main()
{
    printf("%d\n", suma(5,9));
    printf("%d\n", suma(8,6));
    printf("%d\n", suma(30,20));
    printf("%d\n", suma(2,2));
    printf("%d\n", multiplicacion(10,20));
    printf("%d\n", multiplicacion(12,12));
    printf("%d\n", multiplicacion(7,8));

    return 0;
}

// Definiciones

int suma(int a, int b)
{
    return a + b;
}

int multiplicacion(int a, int b)
{
    int m;
    m = a * b;
    return m;
}
