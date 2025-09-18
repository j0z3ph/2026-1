/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que pide n numeros y devuelve el promedio
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int ene;
    int suma = 0;
    double promedio;

    printf("Usuario, ingresa la cantidad de numero a promediar: ");
    scanf("%i", &ene);

    if(ene < 1) {
        printf("Usuario, estas tonoto o que? >:[\n");
        return 1; // Ocurrio un error
    }

    int arrg[ene];

    for (int i = 0; i < ene; i++)
    {
        printf("Usuario, ingresa un numero: ");
        scanf("%i", &arrg[i]);
    }

    // Calculamos el promedio
    for (int i = 0; i < ene; i++) suma += arrg[i];
    
    promedio = (double)suma / (double)ene;
    
    printf("El promedio es: %.4lf\n", promedio);
    
    return 0;
}
