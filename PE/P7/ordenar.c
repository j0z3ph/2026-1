/**
 * @file ordenar.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que ordena un arreglo de numeros desordenados
 * @version 0.1
 * @date 2025-09-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdlib.h> // Aqui esta rand()
#include <time.h>

#define ENE 10

int main()
{
    int arrg[ENE];

    srand(time(NULL));
    

    for (int i = 0; i < ENE; i++)
    {
        arrg[i] = (rand() % 11) + 15;
    }

    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    

    return 0;
}
