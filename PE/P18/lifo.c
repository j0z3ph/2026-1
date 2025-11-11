/**
 * @file lifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Last In First Out (pila) (aka stack)
 * @version 0.1
 * @date 2025-11-05
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertar(int **arrg, int *cont, int valor)
{
    if (*arrg == NULL)
    {
        *arrg = malloc(sizeof(int));
    }
    else
    {
        *arrg = realloc(*arrg, sizeof(int) * (*cont + 1));
        memcpy(*arrg + 1, *arrg, sizeof(int) * (*cont));
    }
    (*arrg)[0] = valor;
    (*cont)++;
}

void listar(int *arrg, int cont)
{
    printf("[ ");
    for (int i = 0; i < cont; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("]\n");
}

int sacar(int **arrg, int *cont)
{
    int eliminado = 0;
    if (*arrg != NULL)
    {
        if (*cont == 1)
        {
            eliminado = (*arrg)[0];
            free(*arrg);
            *cont = 0;
            *arrg = NULL;
        }
        else
        {
            eliminado = (*arrg)[0];
            memcpy(*arrg, *arrg + 1, sizeof(int) * (*cont - 1));
            *arrg = realloc(*arrg, sizeof(int) * (*cont - 1));
            (*cont)--;
        }
    }
    return eliminado;
}

int main()
{
    int *arrg = NULL;
    int cont = 0;

    insertar(&arrg, &cont, 5);
    insertar(&arrg, &cont, 1000);
    insertar(&arrg, &cont, 11);
    insertar(&arrg, &cont, 100000);
    insertar(&arrg, &cont, 314);
    insertar(&arrg, &cont, 16);
    insertar(&arrg, &cont, 2025);

    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    printf("Sacado: %i\n", sacar(&arrg, &cont));

    listar(arrg, cont);

    return 0;
}
