/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa en C :>
 * @version 0.1
 * @date 2025-09-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>

int main()
{
    
    /*
    putc(getc(stdin), stdout);
    putc(getc(stdin), stdout);
    */

    /*
    putchar(getchar());
    putchar(getchar());
    */

    char nombre[20];
    fgets(nombre, 20, stdin);

    puts(nombre);
    
    return 0;
}
