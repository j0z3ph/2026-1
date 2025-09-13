/**
 * @file mas_fors.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Jugando con mas fors
 * @version 0.1
 * @date 2025-09-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        if((i%2) == 0) continue;

        printf("%d ", i);
    }
    
    return 0;
}
