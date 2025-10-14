/**
 * @file cuentadigitos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta los digitos de un numero
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int suma_digitos(int numero) {
    static int contador = 0;
    if(numero > 0) {
        contador++;
        numero /= 10;
        suma_digitos(numero);
    }
    return contador;
}

int main()
{
    int numero;
    printf("Usuario, ingresa un numero entero positivo: ");
    scanf("%i", &numero);
    printf("El numero tiene %i digitos.\n", suma_digitos(numero));
    
    return 0;
}
