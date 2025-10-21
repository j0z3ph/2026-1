/**
 * @file cuentavocales.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta las vocales y las consonantes de una cadena.
 * @version 0.1
 * @date 2025-10-20
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <string.h>
#define N 50

int main()
{
    char cadena[N];
    int cont_v = 0, cont_c = 0, i = 0;
    char aux;
    printf("Usuario, ingresa una cadena: ");
    fgets(cadena, N, stdin);

    while (cadena[i] != '\0')
    {
        aux = cadena[i];
        if (aux >= 65 && aux <= 90)
        {
            // Es una letra mayuscula, la hacemos minuscula
            aux += 32;
        }
        if (aux >= 97 && aux <= 122)
        {
            // Es minuscula
            if (aux == 97 || aux == 101 || aux == 105 || aux == 111 || aux == 117)
            {
                // Es una vocal
                cont_v++;
            }
            else
            {
                // Es consonante
                cont_c++;
            }
        }

        i++;
    }

    printf("La cadena ingresada tiene %i vocal%s y %i consonante%s.\n", cont_v, (cont_v == 1 ? "" : "es"), cont_c, (cont_c == 1 ? "" : "s"));

    return 0;
}
