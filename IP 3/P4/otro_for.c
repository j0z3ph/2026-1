/**
 * @file otro_for.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    int var = 1;
    for(;var <= 10;var++) {
        if(var%2 == 0) continue;
        printf("Hola %i\n", var);   
    }
    
    return 0;
}
