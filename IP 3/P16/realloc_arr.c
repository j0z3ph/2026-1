/**
 * @file realloc_arr.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Realocar memoria dinamica
 * @version 0.1
 * @date 2025-11-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arrg = (int *)malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", arrg + i);
        arrg[i] = i + 1;
    }

    arrg = realloc(arrg, sizeof(int) * 1000);
    for (int i = 0; i < 20; i++)
    {
        printf("%p - %i\n", arrg + i, *(arrg + i));
    }

    free(arrg);
    return 0;
}
