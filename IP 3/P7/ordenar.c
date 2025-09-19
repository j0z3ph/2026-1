/**
 * @file ordenar.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que ordena un arreglo desordenado
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h> // rand()
#include<time.h>

int main()
{
    const unsigned int ENE = 10;
    int arrg[ENE];
    int aux;

    //printf("%lu\n", time(NULL));
    srand(time(NULL));

    for (int i = 0; i < ENE; i++)
    {
        arrg[i] = rand()%10000;
    }

    printf("[ ");
    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("]\n");

    // Ordenamos por burbuja
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
