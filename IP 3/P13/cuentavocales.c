/**
 * @file cuentavocales.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta las vocales y consonantes de una cadena.
 * @version 0.1
 * @date 2025-10-20
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <stdlib.h>

#define N 50

int main()
{
    char cadena[N];
    int cont_v = 0, cont_c = 0, i = 0;
    char aux;
    

    printf("Usuario, ingresa una oracion: ");
    fgets(cadena, N, stdin);

    while (cadena[i] != '\0')
    {
        aux = cadena[i];
        if (aux >= 65 && aux <= 90) // Mayuscula
        {
            aux += 32;
        }
        if (aux >= 97 && aux <= 122) // Minuscula
        {
            if (aux == 97 || aux == 101 || aux == 105 || aux == 111 || aux == 117)
            {
                // Vocal
                cont_v++;
            }
            else
            {
                cont_c++;
            }
        }
        i++;
    }

    printf("La cadena tien %i vocales y %i consonantes.\n", cont_v, cont_c);

    return 0;
}
