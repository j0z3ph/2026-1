/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Punteros y arreglos
 * @version 0.1
 * @date 2025-10-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int a[5] = {6,4,8,2,5};

    //printf("%p - %p - %i\n", a, &a, *a);
    //printf("%p\n%p\n", a, a + 1);

    for (int i = 0; i < 5; i++)
    {
        printf("%p - %i\n", a + i, *(a + i));
    }
    

    return 0;
}
