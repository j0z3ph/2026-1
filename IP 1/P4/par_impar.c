/**
 * @file par_impar.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa de solicita al usuario un numero entero y le indica si es par o impar.
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int numero;
    printf("Usuario, ingrese un numero: ");
    scanf("%d", &numero);

    printf("El numero es %s.\n", (numero & 1) == 0? "PAR" : "IMPAR");    
    return 0;
}
