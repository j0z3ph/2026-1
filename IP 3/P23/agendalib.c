/**
 * @file agendalib.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Biblioteca que nos permite crear y administrar una agenda de contactos.
 * @version 0.1
 * @date 2025-11-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "agendalib.h"
/*** Definiciones de Funciones ***/

void limpiaEnters(char *cadena)
{
    cadena[strlen(cadena) - 1] = '\0';
}

Agenda *newAgenta()
{
    Agenda *agenda = malloc(sizeof(Agenda));
    agenda->lista = NULL;
    //(*agenda).lista = NULL; // Lo mismo de arriba pero con desreferencia
    agenda->cont = 0;
    agenda->listar = listar;
    agenda->agregar = agregar;
    agenda->eliminar = eliminar;
    agenda->seleccionar = seleccionar;

    return agenda;
}

void agregar(Agenda **agenda, Contacto contacto)
{
    if ((*agenda)->lista == NULL)
    {
        // La lista no existe, por lo que la creamos
        (*agenda)->lista = malloc(sizeof(Contacto));
        (*agenda)->lista[0] = contacto;
        (*agenda)->cont = 1;
    }
    else
    {
        // La lista ya existe, debemos agregar
        (*agenda)->lista = realloc((*agenda)->lista, sizeof(Contacto) * ((*agenda)->cont + 1));
        (*agenda)->lista[(*agenda)->cont] = contacto;
        (*agenda)->cont++;
    }
}

void listar(Agenda **agenda)
{
    printf("Lista de contactos\n");
    for (int i = 0; i < (*agenda)->cont; i++)
    {
        printf("Contacto %i\n", i + 1);
        printf("Nombre: %s\nTelefono: %s\nCorreo: %s\n", (*agenda)->lista[i].nombre,
               (*agenda)->lista[i].telefono, (*agenda)->lista[i].correo);
        printf("Fecha de Nacimiento: %02i-%02i-%04i\n", (*agenda)->lista[i].fecha_nac.dia,
               (*agenda)->lista[i].fecha_nac.mes, (*agenda)->lista[i].fecha_nac.anio);
    }
}

int seleccionar(Agenda **agenda, char *titulo)
{
    int indice = -1;
    if ((*agenda)->lista != NULL)
    {
        char *lista_contacto[(*agenda)->cont];
        for (int i = 0; i < (*agenda)->cont; i++)
        {
            lista_contacto[i] = (*agenda)->lista[i].nombre;
        }
        indice = showMenu((*agenda)->cont, lista_contacto, titulo);
    }
    else
    {
        printf("No hay contactos registrados.\n");
    }
    return indice;
}

void eliminar(Agenda **agenda, int indice)
{
    if ((*agenda)->lista != NULL)
    {
        if (indice >= 0 && indice < (*agenda)->cont)
        {
            if ((*agenda)->cont == 1)
            {
                free((*agenda)->lista);
                (*agenda)->lista = NULL;
                (*agenda)->cont = 0;
            }
            else
            {
                memcpy((*agenda)->lista + indice, (*agenda)->lista + indice + 1, sizeof(Contacto) * ((*agenda)->cont - 1 - indice));
                (*agenda)->lista = realloc((*agenda)->lista, sizeof(Contacto) * ((*agenda)->cont - 1));
                (*agenda)->cont--;
            }
        }
    }
}
