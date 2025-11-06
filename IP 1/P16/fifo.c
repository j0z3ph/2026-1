/**
 * @file fifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Haciendo colas (aka queue)
 * @version 0.1
 * @date 2025-11-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void insertar(int **arrg, int *cont, int valor) {
    if(*arrg == NULL) {
        *arrg = malloc(sizeof(int));
    } else {
        *arrg = realloc(*arrg, sizeof(int) * (*cont + 1));
    }
    (*arrg)[*cont] = valor;
    (*cont)++;
}

void insertar_chafa(int *arrg, int cont, int valor) {
    if(arrg == NULL) {
        arrg = malloc(sizeof(int));
    } else {
        arrg = realloc(arrg, sizeof(int) * (cont + 1));
    }
    arrg[cont] = valor;
    cont++;
}


int main()
{
    int *arrg = NULL;
    int cont = 0;

    insertar_chafa(arrg, cont, 8);

    printf("%p - %i\n", arrg, cont);
    
    return 0;
}

