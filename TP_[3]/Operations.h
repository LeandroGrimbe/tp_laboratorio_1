#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "Passenger.h"
#include <ctype.h>

/// @brief Se le pide al usuario que ingrese la ruta del archivo a leer/guardar, y se lo valida que sea de tipo .bin, .dat, .txt, o .csv.
///
/// @param pathAux Variable donde se guarda la ruta ingresada.
/// @param option Variable que le indica a la funcion "stringImput" que lo que se le ingresa es una ruta de archivo.
/// @param typeOfFile Variable que se imprime junto con la tabla. Puede ser BIN o TXT.
/// @return Retorna la ruta validada.
char* getPath(char* pathAux, int option, char* typeOfFile);

/// @brief Le pide al usuario el ingreso de un numero entero, dentro de un rango determinado, y lo valida.
///
/// @param message Mensaje que imprime en pantalla antes de solicitar el ingreso del entero.
/// @param min Valor minimo que puede tomar el numero ingresado por el usuario.
/// @param max Valor maximo que puede tomar el numero ingresado por el usuario.
/// @return Retorna el numero ingresado, validado.
int intImput(char message[], int min, int max);

/// @brief Le pide al usuario el ingreso de un numero flotante, dentro de un rango determinado, y lo valida.
///
/// @param message Mensaje que imprime en pantalla antes de solicitar el ingreso del flotante.
/// @param min Valor minimo que puede tomar el numero ingresado por el usuario.
/// @param max Valor maximo que puede tomar el numero ingresado por el usuario.
/// @return Retorna el numero ingresado, validado.
float floatImput(char* message, int min, int max);

/// @brief Recibe una cadena, la valida segun el tipo de cadena que se maneja, y la retorna.
///
/// @param message Mensaje que imprime en pantalla antes de solicitar el ingreso de la cadena.
/// @param string Cadena auxiliar donde se guarda el ingreso del usuario.
/// @param stringType Variable que le indica a la funcion que tipo de cadena se recibe. 1 si es un nombre / apellido, 2 si es un codigo de vuelo, 3 si es un tipo de pasajero, 4 si es un estado de vuelo, y 5 si es una ruta de archivo.
/// @return Retorna la cadena validada, segun su tipo.
char* stringImput(char* message, char* string, int stringType);

/// @brief Recibe una cadena ingresada por el usuario, y la compara con otras cadenas para validarla.
///
/// @param stringToValidate Cadena a validar.
/// @param string1 Cadena1 a comparar con la cadena ingresada.
/// @param string2 Cadena2 a comparar con la cadena ingresada.
/// @param string3 Cadena3 a comparar con la cadena ingresada.
/// @param index Indice de la cadena, que utiliza para cambiar ciertas letras a Mayus, para darles formato.
/// @return Retorna 0 si la validacion pudo hacerse correctamente, -1 si hubo algun error.
int validateString(char* stringToValidate, char* string1, char* string2, char* string3, int index);

/// @brief En la primera ejecucion, crea un archivo txt con el ID max de los pasajeros del archivo csv. Ya creado, en cada llamado lee el ID MAX, y sobreescribe el ID MAX incrementado 1.
///
/// @return Retorna el nuevo ID MAX.
unsigned int passengerMaxId(void);

/// @brief Recibe 2 elementos genericos, y compara sus ID.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna 1 si ID1 es mayor que ID2, o -1 si ID1 es menor ID2.
int idOrder(void* element1, void* element2);

/// @brief Recibe 2 elementos genericos, y compara sus nombres.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna un numero mayor a cero si NOMBRE1 es mayor que NOMBRE2, un numero menor a cero si NOMBRE2 es mayor que NOMBRE1, o 0 si son iguales.
int nameOrder(void* element1, void* element2);

/// @brief Recibe 2 elementos genericos, y compara sus apellidos.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna un numero mayor a cero si APELLIDO1 es mayor que APELLIDO2, un numero menor a cero si APELLIDO2 es mayor que APELLIDO1, o 0 si son iguales.
int lastNameOrder(void* element1, void* element2);

/// @brief Recibe 2 elementos genericos, y compara sus precios.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna 1 si PRECIO1 es mayor que PRECIO2, -1 si PRECIO1 es menor PRECIO2, o 0 si son iguales.
int priceOrder(void* element1, void* element2);

/// @brief Recibe 2 elementos genericos, y compara sus codigos de vuelo.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna un numero mayor a cero si CODIGOVUELO1 es mayor que CODIGOVUELO2, un numero menor a cero si CODIGOVUELO2 es mayor que CODIGOVUELO1, o 0 si son iguales.
int flyCodeOrder(void* element1, void* element2);

/// @brief Recibe 2 elementos genericos, y compara sus tipos de pasajero.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna un numero mayor a cero si TIPOPASAJERO1 es mayor que TIPOPASAJERO1, un numero menor a cero si TIPOPASAJERO2 es mayor que TIPOPASAJERO1, o 0 si son iguales.
int typePassengerOrder(void* element1, void* element2);

/// @brief Recibe 2 elementos genericos genericos, y compara sus estados de vuelo.
///
/// @param element1 Elemento1 a comparar.
/// @param element2 Elemento2 a comparar.
/// @return Retorna un numero mayor a cero si ESTADOVUELO1 es mayor que ESTADOVUELO2, un numero menor a cero si ESTADOVUELO2 es mayor que ESTADOVUELO1, o 0 si son iguales.
int statusFlightOrder(void* element1, void* element2);

enum
{
	NAMES=1, FLY_CODE=2, TYPE_PASSENGER=3, STATUS_FLIGHT=4, PATH=5
};
#endif /* OPERATIONS_H_ */
