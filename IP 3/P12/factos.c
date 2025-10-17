/**
 * @file factos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer factorial recursivo
 * @version 0.1
 * @date 2025-10-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int facto(int n)
{
    if (n == 0)
        return 1;
    else
        return n * facto(n - 1);
}

int main()
{
    printf("%i\n", facto(5));

    return 0;
}
