/**
 * @file fifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief First In First Out (cola) (aka queue)
 * @version 0.1
 * @date 2025-11-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertar(int **arrg, int *cont, int valor) {
    if(*arrg == NULL) {
        *arrg = malloc(sizeof(int));
    } else {
        *arrg = realloc(*arrg, sizeof(int) * (*cont + 1));
    }
    (*arrg)[*cont] = valor;
    (*cont)++;
}

void listar(int *arrg, int cont) {
    printf("[ ");
    for (int i = 0; i < cont; i++)
    {
        printf("%i ", arrg[i]);
    }
    printf("]\n");
}

int sacar(int **arrg, int *cont) {
    int eliminado = 0;
    if(*arrg != NULL) {
        if(*cont == 1) {
            eliminado = (*arrg)[0];
            free(*arrg);
            *cont = 0;
            *arrg = NULL;
        } else {
            memcpy()
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


    return 0;
}
