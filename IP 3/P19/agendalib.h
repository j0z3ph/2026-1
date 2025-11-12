/**
 * @file agendalib.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Archivo de encabezado de la biblioteca agenda
 * @version 0.1
 * @date 2025-11-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef __AGENDALIB_H__
#define __AGENDALIB_H__
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
    /// @brief Lista los contactos registrados y permite seleccionar uno
    /// @param agenda La agenda
    /// @param titulo El titulo del menu
    /// @return El indice seleccionado o -1 si la agenda esta vacia
    int (*seleccionar)(struct Agenda **self, char *titulo);
    /// @brief Permite eliminar un contacto de la agenda.
    /// @param agenda La agenda
    /// @param indice El indice del contacto a eliminar
    void (*eliminar)(struct Agenda **self, int indice);
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
/// @brief Limpia los enters basura que deja el fgets
/// @param cadena La cadena a limpiar
void limpiaEnters(char *cadena);
/// @brief Lista los contactos registrados y permite seleccionar uno
/// @param agenda La agenda
/// @param titulo El titulo del menu
/// @return El indice seleccionado o -1 si la agenda esta vacia
int seleccionar(Agenda **agenda, char *titulo);
/// @brief Permite eliminar un contacto de la agenda.
/// @param agenda La agenda
/// @param indice El indice del contacto a eliminar
void eliminar(Agenda **agenda, int indice);
#endif