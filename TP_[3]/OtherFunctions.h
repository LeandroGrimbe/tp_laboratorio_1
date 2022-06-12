#ifndef OTHERFUNCTIONS_H_
#define OTHERFUNCTIONS_H_

#include <time.h>
#include "Operations.h"

#define ERRORMESSAGE "\nHubo un error con la solicitud. Volviendo al Menu..."

/// @brief Imprime en pantalla el Menu de opciones principal del programa, y pide que se ingrese la opcion.
///
/// @return Devuelve la opcion ingresada por el usuario
int optionMenu(void);

/// @brief Imprime en pantalla el Menu de opciones del tipo de orden de la lista, y pide que se ingrese la opcion.
///
/// @return Devuelve la opcion ingresada por el usuario.
int sortMenu(void);

/// @brief Notifica al usuario si se hizo el guardado en archivo binario y/o de texto, antes de salir del programa, y le pregunta si desea seguir operando.
///
/// @param binSaveFlag Bandera que indica si se guardaron los datos en un archivo binario. 1 si ya se guardo, 0 si no.
/// @param txtSaveFlag Bandera que indica si se guardaron los datos en un archivo de texto. 1 si ya se guardo, 0 si no.
/// @return Retorna la respuesta del usuario a si quiere seguir o no en el programa.
int exitMenu(int binSaveFlag, int txtSaveFlag);

/// @brief Imprime una imagen al salir del programa.
///
void exitMessage();

/// @brief Define un timer para utilizar en la imprension del final del programa.
///
/// @param number_of_seconds Cantidad de segundos que se quiere hacer un delay.
void delay(float number_of_seconds);

enum
{
	LOAD_TEXT=1, LOAD_BIN=2, ADD=3, MODIFY=4, REMOVE=5, LIST=6, SORT=7, SAVE_TEXT=8, SAVE_BIN=9, EXIT=10
};

enum
{
	ID=0, NAME=1, LASTNAME=2, PRICE=3, FLYCODE=4, TYPEPASSENGER=5, STATUSFLIGHT=6, EXIT_MENU=7
};

#endif /* OTHERFUNCTIONS_H_ */
