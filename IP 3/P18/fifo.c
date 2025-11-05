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


void insertar(int *cola, int cont, int valor) {
    if(cola == NULL) {
        cola = malloc(sizeof(int));
    } else {
        cola = realloc(cola, sizeof(int) * (cont + 1));
    }
    cola[cont] = valor;
    cont++;
}

int main()
{
    int *cola = NULL;
    int cont = 0;
    
    return 0;
}
