/**
 * @file escritura.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Escribiendo en un archivo de texto plano :>
 * @version 0.1
 * @date 2025-11-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    FILE *archi = fopen("carpeta/archivo.txt", "r+");

    if(archi == NULL) {
        printf("Archivo no encontrado T~T\n");
        return 1;
    }

    //fputc(65, archi);
    //fputs("Una cadena de texto", archi);
    //fprintf(archi, "Hola mundo XD %i", 1000);
    //fprintf(archi, "\nOtra linea XD");

    fprintf(archi, "Upsss");

    fclose(archi);
    
    return 0;
}
