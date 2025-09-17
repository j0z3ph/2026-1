/**
 * @file promedio.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que pide al usuario n numeros y devuelve su promedio
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
    
    printf("Usuario, ingrese la cantidad de numeros a promediar: ");
    scanf("%d", &ene);

    // Validamos tamaños de arreglos correctos
    if(ene < 1) {
        printf("No seas tonoto >:[\n");
        return 1;
    }

    // Aqui creamos el arreglo, despues de saber su tamaño
    int arrg[ene];
    
    for (int i = 0; i < ene; i++)
    {
        printf("Usuario, ingresa un numero: ");
        scanf("%d", &arrg[i]);
    }

    // Primero los sumo
    for (int i = 0; i < ene; i++) suma += arrg[i]; 
    
    promedio = (double)suma / (double)ene;

    printf("El promedio es %.3lf\n", promedio);
    
    return 0;
}
