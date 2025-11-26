/**
 * @file lecturabinaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Leyendo un archivo binario XD
 * @version 0.1
 * @date 2025-11-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

typedef struct Contacto
{
    char nombre[100];
    char numero[20];
} Contacto;


int main()
{
    FILE *archi = fopen("archivo.nobinario", "rb");
    int entero;
    Contacto c;

    if(archi == NULL) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    fseek(archi, -sizeof(Contacto), SEEK_END);
    //fread(&entero, sizeof(int), 1, archi);
    fread(&c, sizeof(Contacto), 1, archi);

    printf("%i\n%s\n%s\n", entero, c.nombre, c.numero);

    fclose(archi);
    return 0;
}
