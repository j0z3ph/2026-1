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
#include "agendalib.h"

int main()
{
    Agenda *agenda = newAgenda();
    Contacto tmp;
    int contador = 0;

    FILE *archi = fopen("agenda.op", "ab");
    if (archi == NULL)
    {
        printf("No se encontro la base de datos\n");
        return 1;
    }
    fclose(archi);

    archi = fopen("agenda.op", "rb");
    fread(&contador, sizeof(int), 1, archi);
    fclose(archi);

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

            archi = fopen("agenda.op", "rb+");
            fseek(archi, sizeof(int) + (sizeof(Contacto) * contador), SEEK_SET);
            fwrite(&tmp, sizeof(Contacto), 1, archi);
            contador++;
            fseek(archi, 0, SEEK_SET);
            fwrite(&contador, sizeof(int), 1, archi);
            fclose(archi);
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
            archi = fopen("agenda.op", "rb+");
            fseek(archi, sizeof(int), SEEK_SET);
            printf("Lista de contactos\n");
            for (size_t i = 0; i < contador; i++)
            {
                fread(&tmp, sizeof(Contacto), 1, archi);
            
                printf("Contacto %lu\n", i + 1);
                printf("Nombre: %s\n", tmp.nombre);
                printf("Telefono: %s\n", tmp.telefono);
                printf("Correo: %s\n", tmp.correo);
                printf("Fecha de nacimiento: %02i/%02i/%04i\n",
                       tmp.fechaDeNacimiento.dia,
                       tmp.fechaDeNacimiento.mes,
                       tmp.fechaDeNacimiento.anio);
                printf("###################################\n");
            }

            fclose(archi);
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
