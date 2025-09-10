/**
 * @file 5numeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que solicite al usuario 5 numeros y devuelva el promedio.
 * @version 0.1
 * @date 2025-09-10
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;
    float promedio;
    int ene;
    printf("Usuario, ingresa el valor de n: ");
    scanf("%d", &ene);

    for (int i = 0; i < ene; i++)
    {
        printf("Usuario, ingresa un numero: ");
        scanf("%i", &numero);
        suma = suma + numero;
    }

    promedio = (float)suma / (float)ene;

    printf("El promedio es %.2f\n", promedio);
    return 0;
}
