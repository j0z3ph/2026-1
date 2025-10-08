/**
 * @file app.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Las herramientas
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include"tools.h"

int main(int argc, char const *argv[])
{
    //printf("%i\n", argc);

    for (int i = 0; i < argc; i++)
    {
        //printf("%s\n", argv[i]);
        if(argv[i][0] == '-' && argv[i][1] == 'h' ) {
            printf("esto es la ayuraaaaaaaaa!!!!!!\n");
        }
    }
    
    
    return 0;
}
