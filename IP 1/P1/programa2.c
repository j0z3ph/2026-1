/**
 * @file programa2.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa 2
 * @version 0.1
 * @date 2025-09-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int edad;
    printf("Usuario, ingresa tu edad: ");
    scanf("%i", &edad);

    printf("Tu edad es %i, y tu anio de nacimineto es %d.\n", edad, 2025 - edad);
    
    return 0;
}
