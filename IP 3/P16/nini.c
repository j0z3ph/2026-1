/**
 * @file nini.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Este programa no hace nada
 * @version 0.1
 * @date 2025-10-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void nada() {
    int *a = (int*)malloc(sizeof(int));
    if(a == NULL); // No fue posible reservar espacio en la memoria
    else *a = 10;// 00000000000000000000000000001010
}


int main()
{
    while(100) {
        nada();
    }
    
    return 0;
}
