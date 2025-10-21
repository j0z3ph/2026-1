/**
 * @file alreves.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que imprime una cadena proporcionada por el usuario, al reves
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<string.h>
#define N 50

int tamanio_cadena(char cadena[]) {
    int i = 0;
    while(cadena[i] != '\0') {
        i++;
    }
    return i;
}

int main()
{
    char cadena[N];
    printf("Usuario, ingresa un texto 👻 ");
    fgets(cadena, N, stdin);

    for (int i = tamanio_cadena(cadena) - 1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
    

    return 0;
}
