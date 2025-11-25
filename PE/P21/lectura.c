/**
 * @file lectura.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Lectura de un archivo de texto plano :>
 * @version 0.1
 * @date 2025-11-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

int main()
{
    FILE *archi = fopen("carpeta/archivo.txt", "r");
    //char caracter;
    //char cadena[100];

    int entero;
    char texto[100];
    float flotante;

    if (archi == NULL)
    {
        printf("Archivo no encontrado T-T\n");
        return 1;
    }

    /*caracter = fgetc(archi);
    printf("%i - %c\n", caracter, caracter);
    caracter = fgetc(archi);
    printf("%i - %c\n", caracter, caracter);
    caracter = fgetc(archi);
    printf("%i - %c\n", caracter, caracter);
    caracter = fgetc(archi);
    printf("%i - %c\n", caracter, caracter);
    */

    /*while (!feof(archi))
    {
        caracter = fgetc(archi);
        printf("%c", caracter);
    }*/


    //fgets(cadena, 100, archi);
    //printf("%s", cadena);


    fscanf(archi, "%i %s %f", &entero, texto, &flotante);
    printf("%i\n%s\n%f\n", entero + 10, texto, flotante + 0.06);

    return 0;
}
