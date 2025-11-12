/**
 * @file lifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Haciendo pilas (aka stack)
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
        memcpy(*arrg + 1, *arrg, sizeof(int)* (*cont));
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
            *arrg = NULL;
            *cont = 0;
        }
        else
        {
            eliminado = (*arrg)[0];
            memcpy(*arrg, *arrg + 1, sizeof(int)* (*cont-1));
            *arrg = realloc(*arrg, sizeof(int) * (*cont -1));
            (*cont)--;
        }
    }
    return eliminado;
}

int main()
{
    int *arrg = NULL;
    int cont = 0;

    insertar(&arrg, &cont, 8);
    insertar(&arrg, &cont, 1);
    insertar(&arrg, &cont, 2);
    insertar(&arrg, &cont, 3);
    insertar(&arrg, &cont, 14);
    insertar(&arrg, &cont, 69);
    insertar(&arrg, &cont, 97);
    insertar(&arrg, &cont, 95);

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
    
    printf("Sacado: %i\n", sacar(&arrg, &cont));
    listar(arrg, cont);
    

    return 0;
}
