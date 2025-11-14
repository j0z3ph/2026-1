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
    int entero; // 4
    float flotante; // 4
    double doble; // 8
    char caracter; // 1
};

union Union
{
    int entero; // 4
    float flotante; // 4
    double doble; // 8
    char caracter; // 1
};


int main()
{
    struct Estructura e;
    union Union u;

    e.entero = 10;
    u.entero = 10;

    printf("%i - %i - %lu\n", e.entero, u.entero, sizeof(struct Estructura));

    e.flotante = 3.14;
    u.flotante = 3.14;
    printf("%f - %f - %lu\n", e.flotante, u.flotante, sizeof(union Union));

    e.doble = 3.14;
    u.doble = 3.14;
    printf("%lf - %lf - %lu\n", e.doble, u.doble, sizeof(union Union));

    printf("%i - %i - %lu\n", e.entero, u.entero, sizeof(struct Estructura));

    printf("%lf - %lf - %lu\n", e.doble, u.doble, sizeof(union Union));


    
    return 0;
}
