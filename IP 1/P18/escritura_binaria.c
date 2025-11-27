/**
 * @file escritura_binaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Escribiendo un archivo binario
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
    char correo[50];
} Contacto;


int main()
{
    FILE *archi = fopen("archivo.bin", "wb");
    int entero = 10;
    Contacto c;

    strcpy(c.nombre, "Jose Luis");
    strcpy(c.correo, "correo@mail.com");

    if(archi == NULL) {
        printf("No se encontro el archivo\n");
        return 1;
    }

    fwrite(&entero, sizeof(int), 1, archi);
    fwrite(&c, sizeof(Contacto), 1, archi);

    strcpy(c.nombre, "El chispas");
    strcpy(c.correo, "chispas@osvaldo.chanwish");

    fwrite(&c, sizeof(Contacto), 1, archi);

    fclose(archi);

    return 0;
}
