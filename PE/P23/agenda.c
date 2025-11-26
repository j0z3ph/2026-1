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

/**** Declaraciones de estructuras *********/
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
    void (*agregar)(struct Agenda **agenda, Contacto contacto);
    void (*listar)(struct Agenda **agenda);
    int (*seleccionar)(struct Agenda **agenda);
    void (*eliminar)(struct Agenda **agenda, int indice);
} Agenda;

/****** Declaraciones de funciones *********/

Agenda *newAgenda();
void agregar(Agenda **agenda, Contacto contacto);
void listar(Agenda **agenda);
int seleccionar(Agenda **agenda);
void eliminar(Agenda **agenda, int indice);
int seleccionar2();

int main()
{
    Agenda *agenda = newAgenda();
    int seleccion = 0;
    Contacto tmp;
    int sel = 0;
    int contador = 0;
    FILE *archi = fopen("agenda.ipn", "a");
    if (archi == NULL)
    {
        printf("No se pudo acceder a la base de datos\n");
        return 1;
    }
    fclose(archi);

    // Actualizo contador
    archi = fopen("agenda.ipn", "rb");
    fread(&contador, sizeof(int), 1, archi);
    fclose(archi);

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

            archi = fopen("agenda.ipn", "rb+");
            fseek(archi, sizeof(int) + (sizeof(Contacto) * contador), SEEK_SET);
            fwrite(&tmp, sizeof(Contacto), 1, archi);
            contador++;
            fseek(archi, 0, SEEK_SET);
            fwrite(&contador, sizeof(int), 1, archi);

            fclose(archi);

            limpiaBuffer();
        }
        else if (seleccion == 1)
        {
            // Eliminar
            sel = agenda->seleccionar(&agenda);
            if (sel != -1)
            {
                agenda->eliminar(&agenda, sel);
            }
        }
        else if (seleccion == 2)
        {
            // Editar
            sel = agenda->seleccionar(&agenda);
            if (sel != -1)
            {
                printf("Ingrese el nombre: ");
                fgets(agenda->lista[sel].nombre, 100, stdin);
                agenda->lista[sel].nombre[strlen(agenda->lista[sel].nombre) - 1] = '\0';
                printf("Ingrese el telefono: ");
                fgets(agenda->lista[sel].telefono, 20, stdin);
                agenda->lista[sel].telefono[strlen(agenda->lista[sel].telefono) - 1] = '\0';
                printf("Ingrese el correo: ");
                fgets(agenda->lista[sel].correo, 50, stdin);
                agenda->lista[sel].correo[strlen(agenda->lista[sel].correo) - 1] = '\0';
                printf("Ingrese la fecha de nacimiento [dd-mm-aaaa]: ");
                scanf("%i-%i-%i", &agenda->lista[sel].fecha_nac.dia, &agenda->lista[sel].fecha_nac.mes, &agenda->lista[sel].fecha_nac.anio);

                limpiaBuffer();
            }
        }
        else if (seleccion == 3)
        {
            // Listar
            archi = fopen("agenda.ipn", "rb+");
            fseek(archi, sizeof(int), SEEK_SET);
            
            printf("\tLista de contactos\n");
            for (int i = 0; i < contador; i++)
            {
                fread(&tmp, sizeof(Contacto), 1, archi);
                printf("Contacto %i\n", i + 1);
                printf("Nombre: %s\n", tmp.nombre);
                printf("Telefono: %s\n", tmp.telefono);
                printf("Correo: %s\n", tmp.correo);
                printf("Cumpleaños: %02i/%02i/%04i\n", tmp.fecha_nac.dia,
                       tmp.fecha_nac.mes,
                       tmp.fecha_nac.anio);
                printf("=====================================\n");
            }
            fclose(archi);
        }
        else if (seleccion == 4)
        {
            // Llamar
            sel = seleccionar2();
            if (sel != -1)
            {
                archi = fopen("agenda.ipn", "rb+");
                fseek(archi, sizeof(int) + (sizeof(Contacto) * sel), SEEK_SET);
                fread(&tmp, sizeof(Contacto),1, archi);
                printf("Llamando a %s...", tmp.telefono);
                fclose(archi);
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

/****** Definiciones de funciones *******/
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

int seleccionar2()
{
    int sel = -1;
    int contador = 0;
    Contacto tmp;
    FILE *archi = fopen("agenda.ipn", "rb+");
    fread(&contador, sizeof(int), 1, archi);
    if (contador > 0)
    {
        char lista[contador][100];
        char *l[contador];
        for (size_t i = 0; i < contador; i++)
        {
            fread(&tmp, sizeof(Contacto), 1, archi);
            strcpy(lista[i], tmp.nombre);
            l[i] = lista[i];
        }
        sel = showMenu(contador,l, "Seleccione un contacto");
    }
    else
    {
        printf("No hay contactos registrados.\n");
    }
    fclose(archi);
    return sel;
}

void eliminar(Agenda **agenda, int indice)
{
    if ((*agenda)->lista != NULL)
    {
        if (indice >= 0 && indice < (*agenda)->contador)
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
