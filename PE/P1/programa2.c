/**
 * @file programa2.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de entradas y salidas con formato
 * @version 0.1
 * @date 2025-09-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#define ANIO_ACTUAL 2025

int global; // ESTO ESTA MAL!!!!!

int main()
{
    //const int CONSTANTE = 10;
    

    
    int edad = 0;
    printf("Usuario, ingrese su edad: ");
    scanf("%d", &edad);

    printf("Segun tu edad (%i), naciste en %d.\n", edad, ANIO_ACTUAL - edad);
    
    return 0;
}
