/**
 * @file cuentadigitos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que permite sumar los digitos de un numero
 * @version 0.1
 * @date 2025-10-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>


int suma_digitos(int numero) {
    static int suma = 0;
    if (numero > 0)
    {
        suma += numero % 10;
        numero /= 10;
        suma_digitos(numero);
    }
    return suma;
}

int main()
{
    int numero;
    
    printf("Usuario, ingresa un numero: ");
    scanf("%i", &numero);

    printf("La suma de los digitos es %d.\n", suma_digitos(numero));
    return 0;
}
