/**
 * @file cuenta.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que cuenta hasta n
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

void cuenta(int ene) {
    static int i = 1;
    if ( i <= ene)
    {
        printf("%d ", i);
        i++;
        cuenta(ene);
    }
}

int main()
{
    int ene;
    printf("Ingrese ene: ");
    scanf("%d", &ene);

    cuenta(ene);  
    
    
    return 0;
}
