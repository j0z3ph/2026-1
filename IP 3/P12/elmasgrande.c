/**
 * @file elmasgrande.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que busca el elemento mas grande de un arreglo
 * @version 0.1
 * @date 2025-10-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10



void _genera_aleatorios(int arrg[], int n) {
    static int i = 0;
    if ( i < n)
    {
        arrg[i] = rand()%301;
        i++;
        _genera_aleatorios(arrg, n);
    }
}

void genera_aleatorios(int arrg[], int n) {
    srand(time(NULL));
    _genera_aleatorios(arrg, n);
}

void imprime_arreglo(int arrg[], int n) {
    static int i = 0;
    if ( i < n)
    {
        printf("%i ", arrg[i]);
        i++;
        imprime_arreglo(arrg, n);
    }
}

int el_mas_grande(int arrg[], int n) {
    static int i = 0;
    static int theBigOne = -300;
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
    imprime_arreglo(arrg, N);

    printf("\nEl mas grande es: %i\n", el_mas_grande(arrg, N));
    

    return 0;
}
