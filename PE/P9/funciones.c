/**
 * @file funciones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer funcion :>
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h> 
#include<stdio.h>
#include"operaciones.h"
#include"operaciones.h"
#include"operaciones.h"
#include"operaciones.h"



int main()
{
    int numero1, numero2, efedex;
    //printf("Usuario, ingresa dos numero enteros separados por comas (1,2): ");

    //scanf("%i,%i", &numero1, &numero2);

    efedex = suma_variadica(10,11, 5,2,7,1000,400,8,1,2,3);

    printf("La suma es: %d\n", efedex);

    return 0;
}


