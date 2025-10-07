/**
 * @file operaciones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer biblioteca de funciones :>
 * @version 0.1
 * @date 2025-10-06
 * 
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdarg.h>
// Definicion

int suma(int a, int b) {
    int sum = a + b;
    return sum;
}

int multiplica(int a, int b) {
    return a * b;
}

float divide(int dividendo, int divisor) {
    return (float)dividendo / (float)divisor;
}

int suma_variadica(int n, ...) {
    va_list args;
    va_start(args, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
