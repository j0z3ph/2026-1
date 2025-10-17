/**
 * @file imprime.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Imprime el contenido de un arreglo
 * @version 0.1
 * @date 2025-10-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#define N 10

void imprime_arrg(int arrg[], int n) {
    static int i = 0;
    if ( i < n)
    {
        printf("%i ", arrg[i]);
        i++;
        imprime_arrg(arrg, n);
    }
}


int main()
{
    int arrg[N] = {1,2,3,4,5,6,7,8,9,0};

    imprime_arrg(arrg, N);
    
    return 0;
}
