/**
 * @file ordena.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que ordena un arreglo desordenado
 * @version 0.1
 * @date 2025-09-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h> // rand
#include<time.h> // ojo de agamoto

#define ENE 10


int main()
{
    int arrg[ENE];
    int aux;

    srand(time(NULL));

    for (int i = 0; i < ENE; i++)
    {
        arrg[i] = (rand()%51) - 25;
    }

    printf("[ ");
    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("]\n");

    // Burbuja
    for (int j = 0; j < ENE - 1; j++)
    {
        for (int i = 0; i < ENE - 1 - j; i++)
        {
            if(arrg[i] > arrg[i+1]) {
                aux = arrg[i];
                arrg[i] = arrg[i+1];
                arrg[i+1] = aux;
            }
        }
    }
    
    printf("[ ");
    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("]\n");

    
    
    return 0;
}
