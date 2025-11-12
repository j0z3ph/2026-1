/**
 * @file uniones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer union por el civil
 * @version 0.1
 * @date 2025-11-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

struct Estructura
{
    int entero;
    float flotante;
    double doble;
    char caracter;
};

union Union
{
    int entero;
    float flotante;
    double doble;
    char caracter;
};


int main()
{
    struct Estructura e;
    union Union u;

    e.entero = 10;
    u.entero = 10;

    printf("%i - %i\n", e.entero, u.entero);

    e.flotante = 3.14;
    u.flotante = 3.14;
    printf("%f - %f\n", e.flotante, u.flotante);

    
    return 0;
}
