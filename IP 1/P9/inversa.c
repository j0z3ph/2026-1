/**
 * @file inversa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que determina la inversa de una matriz
 * @version 0.1
 * @date 2025-09-23
 *
 * @copyright Copyright (c) 2025
 *
 */ 
#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 8}, {7, 8, 9}};
    float inv[3][3];

    bool correcto = inversa(matrix, inv);

    if(correcto) {
        imprime(inv);
    }
    

    return 0;
}
