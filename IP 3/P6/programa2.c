/**
 * @file programa2.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que solicita al usuario un numero y devuelve la suma de sus digitos.
 * @version 0.1
 * @date 2025-09-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int numero = 0;
    int suma = 0;
    printf("Usuario, ingresa un numero ;D ");
    scanf("%d", &numero);

    while(numero > 0) {
        suma += (numero % 10);
        numero /= 10;
    }
    
    printf("La suma es: %d\n", suma);

    return 0;
}
