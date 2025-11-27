/**
 * @file lectura_binaria.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Lectura de archivo binario
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
    FILE *archi = fopen("archivo.bin", "rb");
    int entero;
    Contacto c;


    if(archi == NULL) {
        printf("No se encontro el archivo\n");
        return 1;
    }
    

    //fread(&entero, sizeof(int), 1, archi);
    
    fseek(archi,sizeof(Contacto) * -2, SEEK_END);
    
    fread(&c, sizeof(Contacto), 1, archi);


    printf("%i\n", entero);
    printf("%s, %s\n", c.nombre, c.correo);

    fclose(archi);

    return 0;
}
