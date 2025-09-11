/**
 * @file table.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Un pragama que solicita al usuario un numero entero y le devuelve la tabla de multiplicar de ese numero.
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
    int contador = 1; // 1. Variable
    printf("Usuario, ingresa un numero: ");
    scanf("%d", &numero);

    while (contador <= 1000) // 2. Condicion
    {
        printf("%i x %i = %i\n", numero, contador, numero*contador);
        contador++; // 3. Mecanismo
    }
    
/*
    printf("%i x 1 = %i\n", numero, numero*1);
    printf("%i x 2 = %i\n", numero, numero*2);
    printf("%i x 3 = %i\n", numero, numero*3);
    printf("%i x 4 = %i\n", numero, numero*4);
    printf("%i x 5 = %i\n", numero, numero*5);
    printf("%i x 6 = %i\n", numero, numero*6);
    printf("%i x 7 = %i\n", numero, numero*7);
    printf("%i x 8 = %i\n", numero, numero*8);
    printf("%i x 9 = %i\n", numero, numero*9);
    printf("%i x 10 = %i\n", numero, numero*10);
  */  
    return 0;
}
