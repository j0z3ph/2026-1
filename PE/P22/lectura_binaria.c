/**
 * @file lectura_binaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Leyendo un archivo binario
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
    char correo[50];
} Contacto;

int main()
{
    FILE *archi = fopen("archivo.txt", "rb");
    int entero;
    Contacto c, c1;

    if(archi == NULL) {
        printf("El archivo no existe\n");
        return 1;
    }

    //fseek(archi, sizeof(int) + sizeof(Contacto), SEEK_SET);
    
    fseek(archi, sizeof(Contacto) * -2, SEEK_END);


    //fread(&entero, sizeof(int), 1, archi);
    fread(&c, sizeof(Contacto), 1, archi);
    //fread(&c1, sizeof(Contacto), 1, archi);

    printf("%i\n%s\n%s\n", entero, c.nombre, c.correo);
    //printf("%i\n%s\n%s\n", entero, c1.nombre, c1.correo);

    

    fclose(archi);
    return 0;
}
