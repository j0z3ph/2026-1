/**
 * @file lifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Haciendo mi primer pila (aka stack)
 * @version 0.1
 * @date 2025-11-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void insertar(int **pila, int *cont, int valor) {
    if(*pila == NULL) {
        *pila = malloc(sizeof(int));
    } else {
        *pila = realloc(*pila, sizeof(int) * (*cont + 1));
        memcpy(*pila + 1, *pila, sizeof(int) * (*cont));
    }
    (*pila)[0] = valor;
    (*cont)++;
}

void listar(int *pila, int cont) {
    printf("[ ");
    for (int i = 0; i < cont; i++)
    {
        printf("%i ", pila[i]);
    }
    printf("]\n");
}

int sacar(int **pila, int *cont) {
    int sacado = 0;
    if(*pila != NULL) {
        if(*cont == 1) {
            sacado = (*pila)[0];
            free(*pila);
            *pila = NULL;
            *cont = 0;
        } else {
            sacado = (*pila)[0];
            memcpy(*pila, *pila + 1, sizeof(int) * (*cont - 1));
            *pila = realloc(*pila, sizeof(int) * (*cont - 1));
            (*cont)--;
        }
    }
    return sacado;
}

int main()
{
    int *pila = NULL;
    int cont = 0;


    insertar(&pila, &cont, 5);
    insertar(&pila, &cont, 7);
    insertar(&pila, &cont, 4);
    insertar(&pila, &cont, 10);
    insertar(&pila, &cont, 13);
    insertar(&pila, &cont, 20);

    listar(pila, cont);
    //printf("%p - %i\n", pila, cont);

    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);
    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);
    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);
    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);
    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);
    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);
    printf("Sacado: %i\n", sacar(&pila, &cont));
    listar(pila, cont);

    insertar(&pila, &cont, 5);
    listar(pila, cont);


    
    return 0;
}
