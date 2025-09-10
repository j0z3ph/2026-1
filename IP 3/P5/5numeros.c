/**
 * @file 5numeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que pide al usuario 5 numeros y devuelve supromedio
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
    int ene;
    float promedio;
    printf("Usuario, ingresa el valor de n: ");
    scanf("%i", &ene);
    
    for (int i = 0; i < ene; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        suma += numero;
    }

    promedio = (float)suma / (float)ene;

    printf("El promedio de los numero es: %.2f\n", promedio);


    return 0;
}
