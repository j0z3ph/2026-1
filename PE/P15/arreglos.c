/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Arreglos y Punteros
 * @version 0.1
 * @date 2025-10-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int arr[5] = {7,2,3,4,5};
    int *ptr = arr;

    printf("%p - %p\n", ptr, &ptr);
    printf("%p - %p\n", arr, &arr);
    
    return 0;
}
