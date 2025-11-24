/**
 * @file archivos1.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa con archivos :>
 * @version 0.1
 * @date 2025-11-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    // Rutas Relativas: Una ruta que parte de donde me encuentro
    // Rutas Absolutas: Una ruta que parte desde el directorio principal (raiz)

    FILE *archi = fopen("carpeta/archivo.txt", "r+"); // Relativa
    //FILE *archi = fopen("/Users/j0z3ph/Repos/2026-1/IP 3/P21/carpeta/archivo.txt", "a"); // Absoluta

    if(archi == NULL) {
        printf("Archivo no encontrado :c\n");
        return 1;
    }

    fclose(archi);
    
    return 0;
}
