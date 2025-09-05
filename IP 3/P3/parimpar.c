/**
 * @file parimpar.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Este programa determina si un numero
 * proporcionado por el usuario es par o impar
 * @version 0.1
 * @date 2025-09-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int numero;
    printf("Usuario, ingresa un numero o te pico >:c ");
    scanf("%i", &numero);

    printf("El numero ingres es %s.\n", (numero & 1) == 0 ? "PAR" : "IMPAR");
    
    return 0;
}
