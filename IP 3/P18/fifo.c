/**
 * @file fifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Estructura FIFO (aka cola)
 * @version 0.1
 * @date 2025-11-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void insertar(int **cola, int *cont, int valor) {
    if(*cola == NULL) {
        *cola = malloc(sizeof(int));
    } else {
        *cola = realloc(*cola, sizeof(int) * (*cont + 1));
    }
    (*cola)[*cont] = valor;
    (*cont)++;
}

void listar(int *cola, int cont) {
    printf("[ ");
    for (int i = 0; i < cont; i++)
    {
        printf("%i ", cola[i]);
    }
    printf("]\n");
}

int sacar(int **cola, int *cont) {
    int sacado = 0;
    if(*cola != NULL) {
        if(*cont == 1) {
            sacado = (*cola)[0];
            free(*cola);
            *cola = NULL;
            *cont = 0;
        } else {
            sacado = (*cola)[0];
            memcpy(*cola, *cola + 1, sizeof(int) * (*cont - 1));
            *cola = realloc(*cola, sizeof(int) * (*cont - 1));
            (*cont)--;
        }
    }
    return sacado;
}

int main()
{
    int *cola = NULL;
    int cont = 0;


    insertar(&cola, &cont, 5);
    insertar(&cola, &cont, 7);
    insertar(&cola, &cont, 4);
    insertar(&cola, &cont, 10);
    insertar(&cola, &cont, 13);
    insertar(&cola, &cont, 20);

    listar(cola, cont);
    //printf("%p - %i\n", cola, cont);

    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);
    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);
    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);
    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);
    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);
    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);
    printf("Sacado: %i\n", sacar(&cola, &cont));
    listar(cola, cont);

    insertar(&cola, &cont, 5);
    listar(cola, cont);


    
    return 0;
}
