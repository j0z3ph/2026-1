/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Las herramientas
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include<stdio.h>
#include"tools.h"

int main()
{
    char *menu[] = {"Opcion 1", "Opcion 2", "Salir"};
    int opc = showMenu(3, menu, "Menu Principal");
    
    printf("%d\n", opc);
    pausa();
    gotoXY(20, 10);
    printf(":D");
    limpiarPantalla();
    return 0;
}
