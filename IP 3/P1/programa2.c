/**
 * @file programa2.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Pide la edad de una persona y determina su
 * anio de nacimiento
 * @version 0.1
 * @date 2025-09-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#define ANIO_ACTUAL 2025

int global; // ESTO ESTA MAL

int main()
{
    //const int CONSTANTE = 10;
    int edad;
    printf("Usuario, ingrese su edad: ");
    scanf("%d", &edad);

    printf("Su edad es %i y tu anio de nacimento es %i.\n", edad, ANIO_ACTUAL - edad);
    return 0;
}
