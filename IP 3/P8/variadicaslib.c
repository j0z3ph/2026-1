/**
 * @file variadicaslib.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer biblioteca de funciones :>
 * @version 0.1
 * @date 2025-10-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include<stdarg.h>

// Definiciones

int suma(int n, ...)
{
    va_list args;
    va_start(args, n);
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma = suma + va_arg(args, int);
    va_end(args);
    return suma;
}