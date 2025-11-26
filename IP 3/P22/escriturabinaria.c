/**
 * @file escriturabinaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Escribiendo un archivo binario XD
 * @version 0.1
 * @date 2025-11-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include<string.h>

typedef struct Contacto
{
    char nombre[100];
    char numero[20];
} Contacto;



int main()
{   
    FILE *archi = fopen("archivo.nobinario", "wb");
    int entero = 10;
    Contacto c;
    strcpy(c.nombre, "Jose Luis");
    strcpy(c.numero, "12345678");


    if(archi == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    fwrite(&entero, sizeof(int), 1, archi);
    fwrite(&c, sizeof(Contacto), 1, archi);

    strcpy(c.nombre, "Luis Angel");
    strcpy(c.numero, "87654321");

    fseek(archi, sizeof(Contacto) * 3, SEEK_CUR);
    fwrite(&c, sizeof(Contacto), 1, archi);

    fclose(archi);

    return 0;
}
