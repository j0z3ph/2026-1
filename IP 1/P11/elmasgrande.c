/**
 * @file elmasgrande.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que encuentra el elemento mas grande en un arreglo
 * @version 0.1
 * @date 2025-10-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void _genera_aleatorios(int arrg[], int n) {
    static int i = 0;
    if ( i < n)
    {
        arrg[i] = rand()%101;
        i++;
        _genera_aleatorios(arrg, n);
    }
}

void genera_aleatorios(int arrg[], int n) {
    srand(time(NULL));
    _genera_aleatorios(arrg, n);
}

void imprime(int arrg[], int n) {
    static int i = 0;
    if ( i < n)
    {
        printf("%i ", arrg[i]);
        i++;
        imprime(arrg, n);
    }
}

int el_mas_grande(int arrg[], int n) {
    static int theBigOne = -100;
    static int i = 0;
    if ( i < n)
    {
        if(arrg[i] > theBigOne) {
            theBigOne = arrg[i];
        }
        i++;
        el_mas_grande(arrg, n);
    }
    return theBigOne;
}

int main()
{
    int arrg[N];
    

    

    genera_aleatorios(arrg, N);
    imprime(arrg, N);

    printf("\nEl mas grande es: %i\n", el_mas_grande(arrg, N));
    
    
    
    
    return 0;
}
