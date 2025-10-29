/**
 * @file nini.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Nini
 * @version 0.1
 * @date 2025-10-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void nada() {
    int *a = (int *)malloc(sizeof(int));
    *a = 10;
}


int main()
{
    while(100) {
        nada();
    }

    
    return 0;
}
