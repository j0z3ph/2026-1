/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Usando la tools.h
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>
#include"tools.h"
#include "./bibliotecas/func.h"

int main()
{
    char *menu[] = {"Opcion 1", "Opcion 2", "Salir"};

    int resp = showMenu(3, menu, "Menu de Opciones");

    gotoXY(10, 10);
    printf("%d\n", resp);
    pausa();
    limpiarPantalla();
    return 0;
}
