/**
 * @file alreves.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Imprime una cadena al reves
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<string.h>
#define N 50

int tamaniocadena(char cadena[]) {
    int cont = 0;
    while(cadena[cont] != '\0')
        cont++;
    return cont;
}


int main()
{
    char cadena[N];
    int tamanio;
    printf("Usuario, ingresa una cadena: ");
    fgets(cadena, N, stdin);

    tamanio = tamaniocadena(cadena);

    for (int i = tamanio - 1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
    
    
    return 0;
}
