/**
 * @file contador.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta hasta n
 * @version 0.1
 * @date 2025-10-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

void cuenta(int n) {
    static int i = 1;
    if ( i <= n)
    {
        printf("%i ", i);
        i++;
        cuenta(n);
    }
}


int main()
{
    int n;
    printf("Usuario, ingresa un numero: ");
    scanf("%i", &n);
    cuenta(n);
    
    return 0;
}
