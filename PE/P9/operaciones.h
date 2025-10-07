/**
 * @file operaciones.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer biblioteca de funciones :>
 * @version 0.1
 * @date 2025-10-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */ 


#ifndef __OPERACIONES_H__
#define __OPERACIONES_H__

// Declaraciones

/// @brief Suma dos numero enteros
/// @param a El primer numero
/// @param b El segundo numero
/// @return La suma de a y b
int suma(int a, int b);

/// @brief Suma n numeros enteros
/// @param n La cantidad de numeros a sumar
/// @param ... Los numeros, separador por comas
/// @return La suma
int suma_variadica(int n, ...);

/// @brief Multiplica dos numeros
/// @param a Primer numero
/// @param b Segundo numero
/// @return La multiplicacion
int multiplica(int a, int b);

/// @brief Divide dos enteros
/// @param dividendo El dividendo
/// @param divisor El divisor
/// @return La division
float divide(int dividendo, int divisor);

#endif