/**
 * @file recursion.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer recursamiento.
 * @version 0.1
 * @date 2025-10-14
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    printf("%i\n", factorial(5));

    return 0;
}
