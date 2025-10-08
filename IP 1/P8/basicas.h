
#ifndef __BASICAS_H__
#define __BASICAS_H__

// Declaraciones

/// @brief Suma dos numero enteros
/// @param a El primer entero a sumar
/// @param b El segunod entero a sumar
/// @return La suma de a + b
int suma(int a, int b);


/// @brief Funcion que suma n enteros
/// @param n La cantidad de enteros a sumar
/// @param  ... Los enteros separados por comas
/// @return La suma
int suma_variadica(int n, ...);


/// @brief Multiplica dos numero
/// @param a Primer numero
/// @param b Segundo numero
/// @return La multipicacion
int multiplica(int a, int b);

float division(int dividendo, int divisor);


#endif