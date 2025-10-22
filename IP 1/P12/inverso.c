/**
 * @file inverso.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Imprime una cadena en orden inverso
 * @version 0.1
 * @date 2025-10-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<string.h>

#define N 50

int tamanio_cadena(char cadena[]) {
    int cont = 0;
    while(cadena[cont] != '\0') cont++;

    return cont;
}


int main()
{
    char cadena[N];

    printf("Usuario, ingresa una cadena: ");
    fgets(cadena, N, stdin);

    for (int i = tamanio_cadena(cadena) - 1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
    

    
    return 0;
}
