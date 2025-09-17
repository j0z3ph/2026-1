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
#include <stdio.h>
#define ENE 20

int main()
{
    int a = 9;
    int arrg[ENE];

    for (int i = 0; i < ENE; i++)
    {
        //printf("Ingrese un numero: ");
        //scanf("%i", &arrg[i]);
        arrg[i] = i + 1;
    }
    

    printf("[ ");
    for (int i = 0; i < ENE; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("]\n");

    //arrg[10000] = 666;
    //printf("%d\n", arrg[10000]);
    
    return 0;
}
