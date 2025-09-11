/**
 * @file whiles.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con whiles
 * @version 0.1
 * @date 2025-09-10
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int contador = 1; // 1. Una variable con un valor inicial
    while (contador <= 10) // 2. Una condicion que involucra a la variable
    {
        printf("Hola\n");
        contador++; // 3. Un mecanismo con el cual la condicion se haga falsa eventualmente
    }
    return 0;
}
