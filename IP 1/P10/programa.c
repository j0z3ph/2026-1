/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
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
    int resp = showMenu(3, menu, "Titulo del Menu");

    printf("%i\n", resp);

    pausa();
    gotoXY(10,10);
    printf(":D");
    
    return 0;
}
