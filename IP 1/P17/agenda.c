/**
 * @file estructuras.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer estructura
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

/**** Declaraciones de estructuras ******/
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
    char correo[100];
    Fecha fechaDeNacimiento;
} Contacto;

typedef struct Agenda
{
    Contacto *lista;
    int contador;
    void (*agregar)(struct Agenda **agenda, Contacto contacto);
    void (*listar)(struct Agenda **agenda);
    int (*seleccionar)(struct Agenda **agenda);
    void (*eliminar)(struct Agenda **agenda, int indice);
} Agenda;

/****** Declaraciones de variables *******/

/// @brief Permite la creacion de una nueva agenda
/// @return Retorna la nueva agenda
Agenda *newAgenda();
/// @brief Permite agregar un contacto a la agenda
/// @param agenda La agenda
/// @param contacto El contacto
void agregar(Agenda **agenda, Contacto contacto);
/// @brief Permite listar los contactos registrados
/// @param agenda La agenda
void listar(Agenda **agenda);
/// @brief Permite seleccionar de manera interactiva un contacto
/// @param agenda La agenda
/// @return El indice del contacto seleccionado
int seleccionar(Agenda **agenda);
/// @brief Permite eliminar un contacto de la agenda
/// @param agenda La agenda
/// @param indice El indice del contacto a eliminar
void eliminar(Agenda **agenda, int indice);


int main()
{
    Agenda *agenda = newAgenda();
    Contacto tmp;

    char *menu[] = {"Agregar contacto", "Eliminar contacto", "Editar contacto", "Llamar contacto", "Listar contactos", "Salir"};
    int seleccion = 0;
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
            fgets(tmp.correo, 100, stdin);
            tmp.correo[strlen(tmp.correo) - 1] = '\0';
            printf("Ingrese la fecha de nacimiento [dd/mm/aaaa]: ");
            scanf("%i/%i/%i", &tmp.fechaDeNacimiento.dia,
                  &tmp.fechaDeNacimiento.mes,
                  &tmp.fechaDeNacimiento.anio);

            limpiaBuffer();
            agenda->agregar(&agenda, tmp);
        }
        else if (seleccion == 1)
        {
            // Eliminar
            int idx = agenda->seleccionar(&agenda);
            if (idx != -1)
            {
                agenda->eliminar(&agenda, idx);
            }
        }
        else if (seleccion == 2)
        {
            // Editar
            int idx = agenda->seleccionar(&agenda);
            if (idx != -1)
            {
                printf("Ingrese el nombre: ");
                fgets(agenda->lista[idx].nombre, 100, stdin);
                agenda->lista[idx].nombre[strlen(agenda->lista[idx].nombre) - 1] = '\0';
                printf("Ingrese el telefono: ");
                fgets(agenda->lista[idx].telefono, 20, stdin);
                agenda->lista[idx].telefono[strlen(agenda->lista[idx].telefono) - 1] = '\0';
                printf("Ingrese el correo: ");
                fgets(agenda->lista[idx].correo, 100, stdin);
                agenda->lista[idx].correo[strlen(agenda->lista[idx].correo) - 1] = '\0';
                printf("Ingrese la fecha de nacimiento [dd/mm/aaaa]: ");
                scanf("%i/%i/%i", &agenda->lista[idx].fechaDeNacimiento.dia,
                      &agenda->lista[idx].fechaDeNacimiento.mes,
                      &agenda->lista[idx].fechaDeNacimiento.anio);

                limpiaBuffer();
            }
        }
        else if (seleccion == 3)
        {
            // Llamar
            int idx = agenda->seleccionar(&agenda);
            if (idx != -1)
            {
                printf("Llamando a %s (%s)...\n", agenda->lista[idx].nombre, agenda->lista->telefono);
            }
        }
        else if (seleccion == 4)
        {
            // Listar
            agenda->listar(&agenda);
        }
        else
        {
            // Salir
            printf("Adiooooos tonoto 🤪\n");
        }
        if (seleccion != 5)
            pausa();
    }

    return 0;
}

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
