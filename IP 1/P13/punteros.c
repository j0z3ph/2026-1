/**
 * @file punteros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer puntero
 * @version 0.1
 * @date 2025-10-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    void * b;
    int a = 10;
    int *ptr;
    ptr = &a;
    b = &a;
    ptr = (int *)b;

    printf("%p - %p - %i\n", ptr, &ptr, *ptr);
    printf("%p - %i\n", &a, a);

    return 0;
}
