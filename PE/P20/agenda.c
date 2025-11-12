/**
 * @file agenda.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer agenda de contactos :>
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

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct Contacto
{
    char nombre[100];
    char telefono[20];
    char correo[50];
    Fecha fecha_nac;
} Contacto;

typedef struct Agenda
{
    Contacto *lista;
    unsigned int contador;
} Agenda;

Agenda *newAgenda()
{
    Agenda *a = malloc(sizeof(Agenda));
    //(*a).contador = 0;
    a->contador = 0;
    a->lista = NULL;
    return a;
}

void agregar(Agenda **agenda, Contacto contacto)
{
    if ((*agenda)->lista == NULL)
    {
        (*agenda)->lista = malloc(sizeof(Contacto));
        (*agenda)->lista[0] = contacto;
        (*agenda)->contador++;
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
    printf("\tLista de contactos\n");
    for (int i = 0; i < (*agenda)->contador; i++)
    {
        printf("Contacto %i\n", i + 1);
        printf("Nombre: %s\n", (*agenda)->lista[i].nombre);
        printf("Telefono: %s\n", (*agenda)->lista[i].telefono);
        printf("Correo: %s\n", (*agenda)->lista[i].correo);
        printf("Cumpleaños: %02i/%02i/%04i\n", (*agenda)->lista[i].fecha_nac.dia,
               (*agenda)->lista[i].fecha_nac.mes,
               (*agenda)->lista[i].fecha_nac.anio);
        printf("=====================================\n");
    }
}

int seleccionar(Agenda **agenda)
{
    int sel = -1;
    if ((*agenda)->lista != NULL)
    {
        char *lista[(*agenda)->contador];
        for (size_t i = 0; i < (*agenda)->contador; i++)
        {
            lista[i] = (*agenda)->lista[i].nombre;
        }
        sel = showMenu((*agenda)->contador, lista, "Seleccione un contacto");
    }
    else
    {
        printf("No hay contactos registrados.\n");
    }
    return sel;
}

int main()
{
    Agenda *agenda = newAgenda();
    int seleccion = 0;
    Contacto tmp;

    char *menu[] = {"Agregar Contacto", "Eliminar Contacto", "Editar Contacto", "Listar Contactos", "Llamar Contacto", "Salir"};

    while (seleccion != 5)
    {
        seleccion = showMenu(6, menu, "Agenda de Contactos");

        if (seleccion == 0)
        {
            // Agregar
            printf("Ingrese el nombre: ");
            fgets(tmp.nombre, 100, stdin);
            tmp.nombre[strlen(tmp.nombre) - 1] = '\0';
            printf("Ingrese el telefono: ");
            fgets(tmp.telefono, 20, stdin);
            tmp.telefono[strlen(tmp.telefono) - 1] = '\0';
            printf("Ingrese el correo: ");
            fgets(tmp.correo, 50, stdin);
            tmp.correo[strlen(tmp.correo) - 1] = '\0';
            printf("Ingrese la fecha de nacimiento [dd-mm-aaaa]: ");
            scanf("%i-%i-%i", &tmp.fecha_nac.dia, &tmp.fecha_nac.mes, &tmp.fecha_nac.anio);

            limpiaBuffer();
            agregar(&agenda, tmp);
        }
        else if (seleccion == 1)
        {
            // Eliminar
        }
        else if (seleccion == 2)
        {
            // Editar
        }
        else if (seleccion == 3)
        {
            // Listar
            listar(&agenda);
        }
        else if (seleccion == 4)
        {
            // Llamar
            int sel = seleccionar(&agenda);
            if (sel != -1)
            {
                printf("Llamando a %s...", agenda->lista[sel].telefono);
            }
        }
        else if (seleccion == 5)
        {
            printf("Bye bye :P\n");
        }
        if (seleccion != 5)
            pausa();
    }

    return 0;
}
