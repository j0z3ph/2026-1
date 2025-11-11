/**
 * @file curiosidad.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Curiosidades XD
 * @version 0.1
 * @date 2025-11-10
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int suma(int a, int b)
{
    return a + b;
}

int main()
{
    int (*la_suma_curiosa)(int, int);
    la_suma_curiosa = suma;
    printf("%p - %p - %i\n", suma, la_suma_curiosa, la_suma_curiosa(5,6));

    return 0;
}
