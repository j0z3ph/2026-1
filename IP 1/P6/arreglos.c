/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con arreglos
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#define ENE 10

int main()
{
    int a = 0;
    int arrg[ENE];

    /*for (int i = 0; i < ENE; i++)
    {
        printf("Ingresa un numero: ");
        scanf("%d", &arrg[i]);
    }*/
    

    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    
    arrg[1000] = 666;
    printf("\n%i", arrg[1000]);
    
    
    return 0;
}
