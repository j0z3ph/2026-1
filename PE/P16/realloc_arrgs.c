/**
 * @file realloc_arrgs.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Realocando arreglos
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
    int *arr;

    arr = (int *)malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%p\n", arr + i);
        *(arr+i) = i+1;
    }

    arr = (int *)realloc(arr, sizeof(int) * 2000);
    for (int i = 0; i < 12; i++)
    {
        printf("%p - %i\n", arr + i, *(arr+i));
    }

    
    return 0;
}
