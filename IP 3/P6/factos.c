/**
 * @file factos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Factos
 * @version 0.1
 * @date 2025-09-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int numero;
    int facto = 1;
    printf("Usuario, ingresa un numero XD ");
    scanf("%d", &numero);

    for (int i = numero; i >= 1; i--) facto *= i;
    

    printf("El facto es: %i\n", facto);
    
    
    return 0;
}
