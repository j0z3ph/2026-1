/**
 * @file escritura_binaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Escribiendo en un archivo binario
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
    FILE *archi = fopen("archivo.txt", "wb");

    Contacto c;
    int entero = 10;

    strcpy(c.nombre, "Jose Luis");
    strcpy(c.correo, "mail@mail.com");

    if(archi == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    fwrite(&entero, sizeof(int), 1, archi);
    fwrite(&c, sizeof(Contacto), 1, archi);

    fseek(archi, sizeof(Contacto) * 200, SEEK_CUR);

    strcpy(c.nombre, "Cesar Roberto");
    strcpy(c.correo, "cesarsanchez@gmail.com");
    fwrite(&c, sizeof(Contacto), 1, archi);
    
    fclose(archi);
    return 0;
}
