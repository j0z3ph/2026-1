/**
 * @file cuentadigitos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta los digitos de un numero entero
 * @version 0.1
 * @date 2025-10-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

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
    printf("Usuario, ingresa un numero 😏 ");
    scanf("%i", &numero);
    printf("El numero de digitos es %i\n", suma_digitos(numero));

    return 0;
}
