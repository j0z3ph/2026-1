/**
 * @file ifs.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con los ifs
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
    scanf("%i", &edad);

    if (edad >= 18 && edad <= 25)
    {
        printf("Ya tienes que darte de alta en el SAT\n");
    }
    else if (edad > 25 && edad <= 35)
    {
        printf("Paga la hipoteca.\n");
    }
    else if (edad > 35 && edad <= 50)
    {
        printf("Revisate la presion.\n");
    }
    else if (edad > 50)
    {
        printf("Ya hiciste tu testamento.\n");
    }
    else if(edad >= 0)
    {
        printf("Compra Bitcoins.\n");
    } else {
        printf("No seas tonoto, escribe bien >:|\n");
    }

    return 0;
}
