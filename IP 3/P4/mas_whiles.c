/**
 * @file mas_whiles.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Seguimos jugan con whiles
 * @version 0.1
 * @date 2025-09-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int numero;
    int contador = 1; // 1. La variable
    printf("Usuario, ingresa un numero: ");
    scanf("%d", &numero);

    while (contador <= 100) // 2. La condicion que involucra a la variable
    {
        printf("%i x %i = %i\n", numero, contador, numero * contador);
        contador++; // 3. Variamos la variable de tal forma que la condicion se haga falsa en algun momento
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
