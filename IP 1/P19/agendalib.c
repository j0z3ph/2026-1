/**
 * @file agendalib.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi biblioteca XD
 * @version 0.1
 * @date 2025-11-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "agendalib.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/***** Definiciones de Funciones ******/

Agenda *newAgenda()
{
    Agenda *a = malloc(sizeof(Agenda));
    //(*a).contador = 0;
    a->contador = 0;
    a->lista = NULL;
    a->agregar = agregar;
    a->eliminar = eliminar;
    a->listar = listar;
    a->seleccionar = seleccionar;
    return a;
}

void agregar(Agenda **agenda, Contacto contacto)
{
    if ((*agenda)->lista == NULL)
    {
        (*agenda)->lista = malloc(sizeof(Contacto));
        (*agenda)->lista[0] = contacto;
        (*agenda)->contador = 1;
    }
    else
    {
        (*agenda)->lista = realloc((*agenda)->lista, sizeof(Contacto) * ((*agenda)->contador + 1));
        (*agenda)->lista[(*agenda)->contador] = contacto;
        (*agenda)->contador++;
    }
}

void listar(Agenda **agenda)
{
    printf("Lista de contactos\n");
    for (size_t i = 0; i < (*agenda)->contador; i++)
    {
        printf("Contacto %lu\n", i + 1);
        printf("Nombre: %s\n", (*agenda)->lista[i].nombre);
        printf("Telefono: %s\n", (*agenda)->lista[i].telefono);
        printf("Correo: %s\n", (*agenda)->lista[i].correo);
        printf("Fecha de nacimiento: %02i/%02i/%04i\n",
               (*agenda)->lista[i].fechaDeNacimiento.dia,
               (*agenda)->lista[i].fechaDeNacimiento.mes,
               (*agenda)->lista[i].fechaDeNacimiento.anio);
        printf("###################################\n");
    }
}

int seleccionar(Agenda **agenda)
{
    int sel = -1;
    if ((*agenda)->lista != NULL)
    {
        char *nombres[(*agenda)->contador];
        for (size_t i = 0; i < (*agenda)->contador; i++)
        {
            nombres[i] = (*agenda)->lista[i].nombre;
        }
        sel = showMenu((*agenda)->contador, nombres, "Selecciona un contacto");
    }
    else
    {
        printf("No hay contactos registrados.\n");
    }
    return sel;
}

void eliminar(Agenda **agenda, int indice)
{
    if (indice >= 0 && indice < (*agenda)->contador)
    {
        if ((*agenda)->lista != NULL)
        {
            if ((*agenda)->contador == 1)
            {
                free((*agenda)->lista);
                (*agenda)->lista = NULL;
                (*agenda)->contador = 0;
            }
            else
            {
                memcpy((*agenda)->lista + indice, (*agenda)->lista + indice + 1, sizeof(Contacto) * ((*agenda)->contador - indice - 1));
                (*agenda)->lista = realloc((*agenda)->lista, sizeof(Contacto) * ((*agenda)->contador - 1));
                (*agenda)->contador--;
            }
        }
    }
}
