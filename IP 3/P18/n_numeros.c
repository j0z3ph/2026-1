/**
 * @file n_numeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
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
        printf("Ingresa un numero o punto (.) para detener: ");
        scanf("%s", entrada);

        if(entrada[0] != '.') {
            if(arrg == NULL) {
                arrg = malloc(sizeof(int));
            } else {
                arrg = realloc(arrg, sizeof(int) * (cont + 1));
            }

            // Ya tenemos el arreglo listo, con un espacio libre al final
            arrg[cont] = atoi(entrada);
            cont++;
        }
    }

    // Ahora si, promediamos
    for (int i = 0; i < cont; i++)
    {
        suma += arrg[i];
    }

    promedio = (float)suma / (float)cont;
    
    printf("El promedio de los numeros es: %f\n", promedio);

    return 0;
}
