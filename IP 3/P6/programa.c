/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con cosas
 * @version 0.1
 * @date 2025-09-12
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    char entrada[10];
    int suma = 0;

    printf("Usuario, ingresa un numero: ");
    fgets(entrada, 10, stdin);

    for (int i = 0; i < 10; i++)
    {
        if (entrada[i] < 48 || entrada[i] > 57) break;
        suma += (entrada[i] - 48);
    }

    printf("La suma es %i\n", suma);

    return 0;
}
