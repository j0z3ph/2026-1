/**
 * @file while.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con whiles
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int variable = 1; // 1. Variable con el valor inicial
    while(variable <= 100) // 2. Una condicion que eventualmente se haga falsa 
    {
        printf("Hola %i\n", variable);
        variable++; // 3. Variamos la variable para que eventualmente la condicon se haga falsa
    }
    
    return 0;
}
