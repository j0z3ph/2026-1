/**
 * @file switch.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con switches
 * @version 0.1
 * @date 2025-09-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int opcion;
    printf("\tMenu\n");
    printf("1. Opcion 1\n");
    printf("2. Opcion 2\n");
    printf("3. Opcion 3\n");
    printf("4. Opcion 4\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
    {
        int variable = 1;
        printf("Seleccionaste la opcion %i\n", variable);
    }
    break;
    case 2:
        printf("Seleccionaste la opcion 2\n");
        break;
    case 3:
        printf("Seleccionaste la opcion 3\n");
        break;
    case 4:
        printf("Seleccionaste la opcion 4\n");
        break;
    default:
        printf("No sabes leer o que? Ponte pilas :<\n");
        break;
    }

    /*
        if (opcion == 1)
        {
            printf("Seleccionaste la opcion 1\n");
        }
        else if (opcion == 2)
        {
            printf("Seleccionaste la opcion 2\n");
        }
        else if (opcion == 3)
        {
            printf("Seleccionaste la opcion 3\n");
        }
        else if (opcion == 4)
        {
            printf("Seleccionaste la opcion 4\n");
        }
        else
        {
            printf("No sabes leer o que? Ponte pilas :<\n");
        }
    */
    return 0;
}
