/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con arreglos
 * @version 0.1
 * @date 2025-09-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    printf("[ ");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("]\n");

    arr[100] = 666;

    printf("%i\n", arr[100]);
    
    
    
    return 0;
}
