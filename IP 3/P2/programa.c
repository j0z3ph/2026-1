/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de salidas con formato
 * @version 0.1
 * @date 2025-09-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    float numero = -15.52f;

    printf("El numero es % .0f.\n", numero);
    printf("El numero es % .0f.\n", -1 * numero);
    
    return 0;
}
