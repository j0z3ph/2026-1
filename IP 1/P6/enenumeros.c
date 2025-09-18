/**
 * @file enenumeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que solicita al usuario ene numeros y devuelve su promedio
 * @version 0.1
 * @date 2025-09-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    int ene;
    int suma = 0;
    double promedio;

    printf("Usuario, igresa la cantidad de elementos que quiere promediar: ");
    scanf("%d", &ene);

    if(ene < 1) {
        printf("A caso eres &$%%#@ >:[\n");
        return 1;
    }

    int arr[ene];

    for (int i = 0; i < ene; i++)
    {
        printf("Usuario, ingres un numero: ");
        scanf("%i", &arr[i]);
    }

    for (int i = 0; i < ene; i++) suma += arr[i];

    promedio = (double)suma / (double)ene;
    
    printf("El promedio es: %lf\n", promedio);
    
    return 0;
}
