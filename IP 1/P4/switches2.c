/**
 * @file switches.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con Switches.
 * @version 0.1
 * @date 2025-09-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int opcion;
    printf("\tMENU\n");
    printf("1. Opcion 1\n");
    printf("2. Opcion 2\n");
    printf("3. Opcion 3\n");
    printf("4. Opcion 4\n");

    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
    {
        int variable = 1;
        printf("Seleccionaste la opcion %i.\n", variable);
    }
    break;
    case 2:
        printf("Seleccionaste la opcion 2.\n");
        break;
    case 3:
        printf("Seleccionaste la opcion 3.\n");
        break;
    case 4:
        printf("Seleccionaste la opcion 4.\n");
        break;
    default:
        printf("Lee bien TONOTO >:|\n");
        break;
    }

    return 0;
}
