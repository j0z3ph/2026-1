/**
 * @file ifs.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con ifs
 * @version 0.1
 * @date 2025-09-09
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
        printf("No entres a UPIITA\n");
    }
    else if (edad > 25 && edad <= 35)
    {
        printf("Ponte a chambear\n");
    }
    else if (edad > 35 && edad <= 50)
    {
        printf("Saca el riopan\n");
    }
    else if (edad > 50)
    {
        printf("Haz tu testamento\n");
    } else if (edad < 0) {
        printf("No seas tonoto, escribe bien >:c\n");
    }
    else
    {
        printf("Vuelve mas tarde\n");
    }

    return 0;
}
