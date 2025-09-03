/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con los especificadores de formato numerico
 * @version 0.1
 * @date 2025-09-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    float numero = -5.67f;

    printf("El numero es %+.2f.\n", numero);
    printf("El numero es %+.2f.\n", -1 * numero);
    
    return 0;
}
