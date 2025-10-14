/**
 * @file elmasgrande.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que busca al elemento mas grande
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void _generar(int arrg[], int size) {
    static int i = 0;
    if ( i < size)
    {
        arrg[i] = rand() % 101;
        i++;
        _generar(arrg, size);
    }
}


void generar(int arrg[], int size) {
    srand(time(NULL));
    _generar(arrg, size);
}


void imprime(int arrg[], int size) {
    static int i = 0;
    if ( i < size)
    {
        printf("%i ", arrg[i]);
        i++;
        imprime(arrg, size);
    }
}

int elMasGrande(int arrg[], int size) {
    static int theBigOne = -100;
    static int i = 0;
    if ( i < size)
    {
        if(arrg[i] > theBigOne) {
            theBigOne = arrg[i];
        }
        i++;
        elMasGrande(arrg, size);
    }
    return theBigOne;
}

int main()
{
    int arrg[N];

    generar(arrg, N);
    imprime(arrg, N);
    
    printf("\nEl mas grande es %d\n", elMasGrande(arrg, N));
    
    return 0;
}
