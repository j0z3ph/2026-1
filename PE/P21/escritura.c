/**
 * @file escritura.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Escribiendo en un archivo de texto plano
 * @version 0.1
 * @date 2025-11-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    FILE *archi = fopen("carpeta/archivo.txt", "w");

    if(archi == NULL) {
        printf("Upsss, archivo no encontrado :c\n");
        return 1;
    }

    //fputc('@', archi);
    //fputs("Un texto\nHola Mundo XD", archi);

    fprintf(archi, "Esto es un entero: %i\nHola XD", 1000);

    //fflush(archi);

    fclose(archi);

    return 0;
}
