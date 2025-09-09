/**
 * @file ifs.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con ifs
 * @version 0.1
 * @date 2025-09-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int edad;
    printf("Usuario, ingresa tu edad: ");
    scanf("%d", &edad);

    if (edad >= 18 && edad <= 25)
    {
        int var = 0;
        printf("Ya te diste de alta en el SAT?\n");
    }
    else if (edad > 25 && edad <= 40)
    {
        printf("Ya pagale al Coppel.\n");
    }
    else if (edad > 40 && edad < 60)
    {
        printf("Ya te jubilaste?\n");
    }
    else if (edad >= 60)
    {
        printf("De quien son los terrenos?\n");
    }
    else if (edad < 1)
    {
        printf("No seas tonoto, escribe bien >:c\n");
    }
    else
    {
        printf("Se feliz, mientras te dure.\n");
    }
    return 0;
}
