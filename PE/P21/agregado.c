/**
 * @file agregado.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Agregando contenidos en archivo de texto plano
 * @version 0.1
 * @date 2025-11-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

int main()
{
    FILE *archi = fopen("carpeta/archivo.txt", "a");

    if(archi == NULL) {
        printf("Upppppsssssss\n");
        return 1;
    }

    fprintf(archi, "Upsss");

    fclose(archi);
    
    return 0;
}
