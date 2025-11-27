#ifndef __AGENDALIB_H__
#define __AGENDALIB_H__
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

#endif