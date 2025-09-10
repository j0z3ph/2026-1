/**
 * @file fors.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Las tablas segunda vuelta
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
    int contador = 1; // 1. La variable
    printf("Usuario, ingresa un numero: ");
    scanf("%d", &numero);

    for (;; ) // 2. La condicion que involucra a la variable
    {
        printf("%i x %i = %i\n", numero, contador, numero * contador);
        contador++; // 3. Variamos la variable de tal forma que la condicion se haga falsa en algun momento
        if(contador > 100) break;
    }
    
    return 0;
}
