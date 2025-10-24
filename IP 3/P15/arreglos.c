/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Arreglos y punteros??
 * @version 0.1
 * @date 2025-10-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int arrg[5] = {9,2,3,4,5};

    //printf("%p - %i - %p\n", arrg, *arrg, &arrg);
    // Aplicando aritmetica de punteros
    for (int i = 0; i < 5; i++)
    {
        printf("%p - %i\n", arrg + i, *(arrg + i));
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%p - %i\n", arrg + i, arrg[i]);
    }
    
    
    
    return 0;
}
