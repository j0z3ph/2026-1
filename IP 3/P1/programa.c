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
#include <stdio.h>

int main()
{
    // Linea
    /*char letra = getc(stdin); // hago una variable
    putc(letra, stdout);
    letra = getc(stdin);
    putc(letra, stdout);
    letra = getc(stdin);
    putc(letra, stdout);
    */
    
    /*char letra = getchar();
    putchar(letra);
    letra = getchar();
    putchar(letra);
    letra = getchar();
    putchar(letra);
    */


    char cadena[20];
    fgets(cadena, 20, stdin);
    puts(cadena);

    puts("Adios");
    
    return 0;
}
