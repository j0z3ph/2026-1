/**
 * @file suma_digitos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Solicita al usuario un numero entero y devuelve la suma de sus digitos.
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int numero;
    int suma = 0;
    printf("Usuario, ingresa un numero: ");
    scanf("%d", &numero);

    while(numero > 0) {
        suma += (numero % 10);
        numero /= 10;
    }

    printf("La suma de los digitos es %d.\n", suma);

    return 0;
}
