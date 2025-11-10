/**
 * @file estructura.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer estructura :>
 * @version 0.1
 * @date 2025-11-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>

typedef int entero;
typedef float flotante;
typedef double doble;
typedef char caracter;

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
} Fecha;


typedef struct Contacto // Tipo de dato abstracto
{
    char nombre[50];
    char telefono[15];
    char correo[50];
    Fecha fecha_nac;
} Contacto;


int main()
{
    struct Fecha f;
    Fecha f1;
    
    
    int a;
    entero b;
    caracter d = 'a';

    Contacto c;
    c.fecha_nac.dia = 25;
    c.fecha_nac.mes = 10;
    c.fecha_nac.anio = 2007;
    
    return 0;
}
