/**
 * @file archivos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer archivo :>
 * @version 0.1
 * @date 2025-11-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include <stdio.h>

 int main()
 {
    FILE *archi = fopen("archivo.txt", "a");

    if(archi == NULL) {
        printf("Archivo no encontrado :c\n");
        return 1;
    }
    
    return 0;
 }
 