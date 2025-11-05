/**
 * @file ene_numeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que solicita al usuario numeros y devuelve el promedio
 * @version 0.1
 * @date 2025-11-05
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arrg = NULL;
    int cont = 0;

    int suma = 0;
    float promedio;

    char entrada[10];
    entrada[0] = '\0';

    while (entrada[0] != '.')
    {
        printf("Ingrese un numero o punto (.) para terminar: ");
        scanf("%s", entrada);

        if(entrada[0] != '.') {

            if(arrg == NULL) {
                // Hay que crear el arreglo
                arrg = malloc(sizeof(int));
            } else {
                arrg = realloc(arrg, sizeof(int) * (cont + 1));
            }

            arrg[cont] = atoi(entrada);
            cont++;
        }
    }

    // Calcular el promedio
    for (int i = 0; i < cont; i++)
    {
        suma += arrg[i];
    }
    
    promedio = (float)suma / (float)cont;

    printf("El promedio es: %.3f\n", promedio);

    free(arrg);

    return 0;
}
