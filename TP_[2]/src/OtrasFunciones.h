#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_

#include "ArrayPassenger.h"

/// @brief Imprime en pantalla el Menu de opciones Principal del programa, y pide el ingreso de un entero.
///
/// @return Devuelve la opcion elegida por el usuario.
int menuOpciones(void);


/// @brief Recibe el vector de pasajeros, y pide los datos de 1 ticket, y los carga en la primera posicion libre. Si no hay mas posiciones libres, se notifica por pantalla.
///
/// @param list Vector de pasajeros.
/// @param len Tamaño del vector de pasajeros.
/// @param pasajeroID Id del pasajero cargado anteriormente (0 si todavia no se cargo ninguno).
/// @return Si pudo cargarse correctamente, devuelve el ID del ticket recien cargado. Caso contrario, devuelve el ID del ticket anterior.
int altaTicket(Passenger* list, int len, int pasajeroID);


/// @brief Recibe el vector de pasajeros, pide el id de alguno de sus tickets, y cambia de este alguno de sus datos, segun se requiera. Si no se encuentra el id, se notifica por pantalla.
///
/// @param list Vector de pasajeros.
/// @param len Tamaño del vector de pasajeros.
/// @param cantTickets Cantidad de tickets disponibles. Si es <1 muestra un error.
void modificarTicket(Passenger* list, int len, int cantTickets);


/// @brief Recibe el vector de pasajeros, pide el id del ticket que desea eliminar, y si se encuentra, se le hace una baja logica. Si no, se notifica por pantalla.
///
/// @param list Vector de pasajeros.
/// @param len Tamaño del vector de pasajeros.
/// @param cantTickets Cantidad de tickets disponibles. Si es <1 muestra un error.
/// @return Si se pudo borrar correctamente, devuelve la cantidad de tickets descontada, caso contrario la retorna igual que como la recibio.
int bajaTicket(Passenger* list, int len, int cantTickets);


/// @brief Recibe el vector de pasajeros, e informa en pantalla los datos de los tickets, segun condiciones predeterminadas.
///
/// @param list Vector de pasajeros.
/// @param len Tamaño del vector de pasajeros.
/// @param cantTickets Cantidad de tickets disponibles. Si es <1 muestra un error.
void informeTickets(Passenger* list, int len, int cantTickets);


/// @brief Imprime en pantalla el Menu de opciones para modificar un Ticket, y pide un numero entero.
///
/// @return Devuelve la opcion elegida por el usuario.
int submenuModificar(void);


/// @brief Imprime en formato de tabla cada tipo de dato que se encuentra en el vector de pasajeros.
///
void tablaPasajeros(void);


/// @brief Imprime en pantalla un mensaje, notificando que está volviendo al Menu Principal.
///
void volverMenu(void);


/// @brief Imprime un mensaje de error cuando se intenta realizar alguna de las tareas, sin haber cargado antes ningun Ticket.
///
void errorSinAltas(void);

enum
{
	ALTA=1, MODIFICAR=2, BAJA=3, INFORMAR=4, HARDCODEO=5, NOMBRE=1, APELLIDO=2, PRECIO=3, TIPO_PASAJERO=4, CODIGO_VUELO=5, SALIR=0
};

#endif
