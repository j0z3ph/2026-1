/**
 * @file agenda.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer agenda de contactos :>
 * @version 0.1
 * @date 2025-11-10
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

/*** Definiciones de Estructuras ***/

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct Contacto
{
    char nombre[100];
    char telefono[15];
    char correo[100];
    Fecha fecha_nac;
} Contacto;

typedef struct Agenda
{
    Contacto *lista; // Representa la lista dinamica
    int cont;        // Representa la cantidad de elementos en la lista
    /// @brief Permite agregar un contacto a la agenda
    /// @param self La misma instancia de la agenda
    /// @param contacto El contacto
    void (*agregar)(struct Agenda **self, Contacto contacto);
    /// @brief Lista en pantalla los contactos
    /// @param self Yo mismo
    void (*listar)(struct Agenda **self);
} Agenda;

/*** Declaraciones de Funciones ***/

/// @brief Crea una nueva instancia en memoria dinamida de una agenda
/// @return El puntero de la nueva variable
Agenda *newAgenta();
/// @brief Permite agregar un contacto a la agenda
/// @param agenda La agenda
/// @param contacto El contacto
void agregar(Agenda **agenda, Contacto contacto);
/// @brief Lista en pantalla los contactos
/// @param agenda La agenda
void listar(Agenda **agenda);
void limpiaEnters(char *cadena);

int main()
{
    char *menu[] = {"Agregar Contacto", "Buscar Contacto", "Editar Contacto", "Eliminar Contacto", "Listar Contactos", "Salir"};
    int seleccion = 0;

    Agenda *agenda = newAgenta();
    Contacto tmp;

    while (seleccion != 5)
    {
        seleccion = showMenu(6, menu, "Agenda de Contactos");
        if (seleccion == 0)
        {
            // Agregar contacto
            printf("Ingrese el nombre: ");
            fgets(tmp.nombre, 100, stdin);
            limpiaEnters(tmp.nombre);
            printf("Ingrese el telefono: ");
            fgets(tmp.telefono, 15, stdin);
            limpiaEnters(tmp.telefono);
            printf("Ingrese el correo: ");
            fgets(tmp.correo, 100, stdin);
            limpiaEnters(tmp.correo);
            printf("Ingrese la fecha de nacimineto [dd-mm-aaaa]: ");
            scanf("%i-%i-%i", &tmp.fecha_nac.dia, &tmp.fecha_nac.mes, &tmp.fecha_nac.anio);
            agenda->agregar(&agenda, tmp);
            limpiaBuffer();
        }
        else if (seleccion == 1)
        {
            // Buscar contacto
        }
        else if (seleccion == 2)
        {
            // Editar contacto
        }
        else if (seleccion == 3)
        {
            // Eliminar contacto
        }
        else if (seleccion == 4)
        {
            // Listar contactos
            agenda->listar(&agenda);
        }
        else
        {
            // Salir
            printf("Adios :D");
        }
        if (seleccion != 5)
            pausa();
    }
    return 0;
}

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
