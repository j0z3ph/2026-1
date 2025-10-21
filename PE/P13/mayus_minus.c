/**
 * @file mayus_minus.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Convierte una cadena a mayusculas y minusculas
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 100

int main()
{
    char cadena[N];
    char aux;
    printf("Usuario, ingresa una cadena: ");
    fgets(cadena, N, stdin);

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        aux = cadena[i];
        if(aux >= 97 && aux <= 122) {
            aux-=32;
        }
        printf("%c", aux);
    }
    
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        aux = cadena[i];
        if(aux >= 65 && aux <= 90) {
            aux+=32;
        }
        printf("%c", aux);
    }
    
    return 0;
}
