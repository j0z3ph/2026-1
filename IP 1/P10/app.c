/**
 * @file app.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main(int argc, char const *argv[])
{
    //printf("%i\n", argc);
    for (int i = 0; i < argc; i++)
    {
        if(argv[i][0] == '-' && argv[i][1] == 'h') {
            printf("Esto es la ayuda ;D\n");
        }
        //printf("%s\n", argv[i]);
    }
    
    return 0;
}
