/**
 * @file estructuras.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer estructura :>
 * @version 0.1
 * @date 2025-11-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

typedef int entero;

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;

    /*void agrega_dias(int dias) {
        dia += dias;
    }*/
} Fecha;


int main()
{
    int variable;
    entero var2;
    

    struct Fecha fecha;
    Fecha f1;
    fecha.dia = 1;
    fecha.mes = 12;
    fecha.anio = 2000;
    
    return 0;
}
