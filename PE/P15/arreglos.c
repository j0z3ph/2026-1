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
#include <stdio.h>

int main()
{
    int arr[5] = {7, 2, 3, 4, 5};
    // int *ptr = arr;

    // printf("%p - %p\n", ptr, &ptr);
    // printf("%p - %p - %i\n", arr, &arr, *arr);

    for (int i = 0; i < 5; i++)
    {
        printf("%p - %i\n", arr + i, *(arr + i));
    }

    return 0;
}
