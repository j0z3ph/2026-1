/**
 * @file escritura.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Escribiendo un archvivo de texto
 * @version 0.1
 * @date 2025-11-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    FILE *archi = fopen("archivo.txt", "w");
    
    if(archi == NULL) {
        printf("El archivo no existe\n");
        return 1;
    }

    //fputc('H', archi);
    //fputs("Una cadena", archi);

    fprintf(archi, "Esto es un entero: %i\nEsto es un flotante: %f", 6, 3.14);

    fclose(archi);
    
    return 0;
}
