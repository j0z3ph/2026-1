/**
 * @file arreglo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que imprime los elementos de un arreglo
 * @version 0.1
 * @date 2025-10-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#define N 10

void imprime(int arrg[], int n) {
    static int i = 0;
    if ( i < n)
    {
        printf("%i ", arrg[i]);
        i++;
        imprime(arrg, n);
    }
}

int main()
{
    int arrg[N] = {1,2,3,4,5,6,7,8,9,0};

    imprime(arrg, N);
    
    return 0;
}
