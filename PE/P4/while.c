/**
 * @file while.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con los whiles
 * @version 0.1
 * @date 2025-09-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int variable = 1; // 1. Una variable con un valor inicial
    while (variable <= 100) // 2. Una condicion que involucre a la variable para que eventualmente se haga falsa
    {
        printf("Hola %i\n", variable);
        variable++; // 3. Mecanismo con el cual vario la variable para que la condicion se haga falsa eventualmente
    }

    return 0;
}
