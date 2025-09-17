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

    //printf("%lu\n", time(NULL));
    srand(time(NULL));

    for (int i = 0; i < ENE; i++)
    {
        arrg[i] = rand()%100;
    }

    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    
    


    
    return 0;
}
