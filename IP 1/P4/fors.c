/**
 * @file fors.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con fors
 * @version 0.1
 * @date 2025-09-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int numero;
     // 1. Variable
    printf("Usuario, ingresa un numero: ");
    scanf("%d", &numero);

    for (int contador = 1;contador <= 10; contador++) // 2. Condicion
    {
        printf("%i x %i = %i\n", numero, contador, numero*contador);
         // 3. Mecanismo
    }
    
    return 0;
}
