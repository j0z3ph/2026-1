/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa en C :>
 * @version 0.1
 * @date 2025-08-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    /*
    putc(getc(stdin), stdout);
    putc(getc(stdin), stdout);
    putc(getc(stdin), stdout);
    */

    /*putchar(getchar());
    putchar(getchar());
    putchar(getchar());
    */

    /*char letra = getc(stdin);
    putc(letra, stdout);
    */

    char cadena[20];
    fgets(cadena, 20, stdin);

    puts(cadena);


    return 0;
}
