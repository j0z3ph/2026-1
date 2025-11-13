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
            // Llamar
        }
        else if (seleccion == 4)
        {
            // Listar
            listar(&agenda);
        }
        else
        {
            // Salir
            printf("Adiooooos tonoto 🤪\n");
        }
        if(seleccion != 5) pausa();
    }

    return 0;
}
