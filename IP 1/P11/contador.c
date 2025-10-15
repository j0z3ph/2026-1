/**
 * @file contador.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta hasta n numeros
 * @version 0.1
 * @date 2025-10-14
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
    printf("Usuario, ingrese el valor de n: ");
    scanf("%d", &n);

    cuenta(n);
    
    return 0;
}
