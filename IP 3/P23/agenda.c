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
#include "agendalib.h"

int main()
{
    char *menu[] = {"Agregar Contacto", "Llamar Contacto", "Editar Contacto", "Eliminar Contacto", "Listar Contactos", "Salir"};
    int seleccion = 0;

    Agenda *agenda = newAgenta();
    Contacto tmp;
    int contador = 0;

    FILE *archi = fopen("agenda.gg", "ab");
    if (archi == NULL)
    {
        printf("No se pudo abrir la base de datos");
        return 1;
    }
    fclose(archi);

    archi = fopen("agenda.gg", "rb");
    fread(&contador, sizeof(int), 1, archi);
    fclose(archi);

    int indice;

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

            archi = fopen("agenda.gg", "rb+");
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
            // Llamar contacto
            indice = agenda->seleccionar(&agenda, "Seleccione un contacto a llamar");
            if (indice > -1)
                printf("Llamando a %s...\n", agenda->lista[indice].telefono);
        }
        else if (seleccion == 2)
        {
            // Editar contacto
            indice = agenda->seleccionar(&agenda, "Seleccione un contacto a editar");

            if (indice > -1)
            {
                printf("Ingrese el nombre: ");
                fgets(agenda->lista[indice].nombre, 100, stdin);
                limpiaEnters(agenda->lista[indice].nombre);
                printf("Ingrese el telefono: ");
                fgets(agenda->lista[indice].telefono, 15, stdin);
                limpiaEnters(agenda->lista[indice].telefono);
                printf("Ingrese el correo: ");
                fgets(agenda->lista[indice].correo, 100, stdin);
                limpiaEnters(agenda->lista[indice].correo);
                printf("Ingrese la fecha de nacimineto [dd-mm-aaaa]: ");
                scanf("%i-%i-%i", &agenda->lista[indice].fecha_nac.dia, &agenda->lista[indice].fecha_nac.mes, &agenda->lista[indice].fecha_nac.anio);
                limpiaBuffer();
            }
        }
        else if (seleccion == 3)
        {
            // Eliminar contacto
            indice = agenda->seleccionar(&agenda, "Seleccione un contacto a eliminar");

            if (indice > -1)
            {
                agenda->eliminar(&agenda, indice);
            }
        }
        else if (seleccion == 4)
        {
            // Listar contactos
            printf("Lista de contactos\n");
            archi = fopen("agenda.gg", "rb+");
            fseek(archi, sizeof(int), SEEK_SET);
            for (int i = 0; i < contador; i++)
            {
                fread(&tmp, sizeof(Contacto), 1, archi);
                printf("Contacto %i\n", i + 1);
                printf("Nombre: %s\nTelefono: %s\nCorreo: %s\n", tmp.nombre,
                       tmp.telefono, tmp.correo);
                printf("Fecha de Nacimiento: %02i-%02i-%04i\n", tmp.fecha_nac.dia,
                       tmp.fecha_nac.mes, tmp.fecha_nac.anio);
            }
            fclose(archi);
        }
        else
        {
            // Salir
            printf("Adios :D\n");
        }
        if (seleccion != 5)
            pausa();
    }
    return 0;
}
