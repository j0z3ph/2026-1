/**
 * @file cuentadigitos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que permite contar el numero de digitos de un numero
 * @version 0.1
 * @date 2025-10-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>


int suma_digitos(int numero) {
    static int cont = 0;
    if (numero > 0)
    {
        cont++;
        numero /= 10;
        suma_digitos(numero);
    }
    return cont;
}

int main()
{
    int numero;
    
    printf("Usuario, ingresa un numero: ");
    scanf("%i", &numero);

    printf("El numero tiene %d digitos.\n", suma_digitos(numero));
    return 0;
}
