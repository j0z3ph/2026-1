/**
 * @file inversa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que calcula la inversa de una matriz de 3x3
 * @version 0.1
 * @date 2025-09-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdbool.h>
#include"matrices.h"

int main()
{
    int matrix[3][3] = {{1,2,3}, 
                        {4,9,6}, 
                        {7,8,9}};
    
    float inv[3][3];
    imprime_int(matrix);
    bool correcto = inversa(matrix, inv);
    if(correcto) {
        imprime_float(inv);
    } 

    
    return 0;
}
