/**
 * @file referencias.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer paso por referencia
 * @version 0.1
 * @date 2025-10-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int suma_valor(int a, int b)
{
    a++;
    b++;
    return a + b;
}

int suma_ref(int *a, int *b)
{
    (*a)++;
    (*b)++;
    return *a + *b;
}

int main()
{
    int a = 5;
    int b = 18;

    printf("%i\n%i\n%i\n",suma_ref(&a,&b), a, b);

    return 0;
}
