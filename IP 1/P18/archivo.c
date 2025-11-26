/**
 * @file archivo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de archivos XD
 * @version 0.1
 * @date 2025-11-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    FILE *archi = fopen("archivo.txt", "a");

    if(archi == NULL) {
        printf("El archivo no existe :c\n");
        return 1;
    }

    //fflush(archi);

    fclose(archi);
    
    return 0;
}
