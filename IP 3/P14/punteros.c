/**
 * @file punteros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer apuntador/puntero 😏
 * @version 0.1
 * @date 2025-10-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int a = 7;
    int * ptr;
    ptr = &a;
    void *var = &a;

    double *ptr2 = (double *)var;

    printf("%p - %p - %i\n", &a, &ptr, a);

    return 0;
}
