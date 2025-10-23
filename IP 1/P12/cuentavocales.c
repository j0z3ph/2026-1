/**
 * @file cuentavocales.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta la cantidad de vocales y consonantes de una cadena
 * @version 0.1
 * @date 2025-10-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#define N 50
int main()
{
    char cadena[N];
    int cont_vocales = 0, cont_consonantes = 0, i = 0;
    char temp;
    printf("Usuario, ingresa una cadena: ");
    fgets(cadena, N, stdin);

    while (cadena[i] != '\0')
    {
        temp = cadena[i];
        if (temp >= 65 && temp <= 90)
        {
            // Mayuscula
            temp += 32;
        }

        if (temp >= 97 && temp <= 122)
        {
            // Es una minuscula
            if (temp == 97 || temp == 101 ||
                temp == 105 || temp == 111 ||
                temp == 117)
            {
                cont_vocales++;
            }
            else
            {
                cont_consonantes++;
            }
        }

        i++;
    }

    printf("La cadena tiene %i vocales y %i consonantes.\n", cont_vocales, cont_consonantes);

    return 0;
}
