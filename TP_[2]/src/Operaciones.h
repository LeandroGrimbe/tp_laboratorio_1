#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include "ArrayPassenger.h"

/// @brief Imprime en pantalla un mensaje, pide un numero entero y lo valida en un rango determinado.
///
/// @param mensaje Mensaje que se le imprime al usuario, antes de pedirle el numero.
/// @param min Valor minimo que puede tomar el numero ingresado.
/// @param max Valor maximo que puede tomar el numero ingresado.
/// @return Devuelve el numero pedido, validado.
int ingresoEntero(char mensaje[50], int min, int max);


/// @brief Imprime en pantalla un mensaje, pide un numero flotante y lo valida en un rango determinado.
///
/// @param mensaje Mensaje que se le imprime al usuario, antes de pedirle el numero.
/// @param min Valor minimo que puede tomar el numero ingresado.
/// @param max Valor maximo que puede tomar el numero ingresado.
/// @return Devuelve el numero pedido, validado.
float ingresoFloat(char mensaje[50], int min, int max);


/// @brief Imprime en pantalla un mensaje, pide una cadena y la valida con el tamaño recibido.
///
/// @param mensaje Mensaje que se le imprime al usuario, antes de pedirle la cadena.
/// @param cadenaAux String auxiliar donde se guardara la cadena validada.
/// @param cadenaLen Tamaño maximo que puede tomar la cadena ingresada.
void ingresoCadena(char mensaje[50], char cadenaAux[], int cadenaLen);


/// @brief Recibe el vector de pasajeros, e intercambia los valores entre dos de sus posiciones.
///
/// @param list Vector de pasajeros donde se encuentran los datos a intercambiar.
/// @param indice1 Indice de la primer posicion a cambiar.
/// @param indice2 Indice de la segunda posicion a cambiar.
void cambioArray(Passenger* list, int indice1, int indice2);


/// @brief Recibe el vector de pasajeros, y le asigna a cada posicion su estado de vuelo correspondiente, segun su id flyStatusID.
///
/// @param list Vector de pasajeros donde se encuentran los datos a completar.
/// @param len Tamaño del vector de pasajeros.
void cargaEstados(Passenger* list, int len);


/// @brief Recibe el vector de pasajeros, y le asigna a cada posicion su tipo de pasajero correspondiente, segun su id TypePassengerID.
///
/// @param list Vector de pasajeros donde se encuentran los datos a completar.
/// @param len Tamaño del vector de pasajeros.
void cargaTiposPasajero(Passenger* list, int len);


/// @brief Recibe el vector de pasajeros, y precarga los datos de 6 pasajeros.
///
/// @param list Vector de pasajeros donde se encuentran los datos a completar.
/// @param len Tamaño del vector de pasajeros.
void hardcodeoPasajeros(Passenger* list, int len);


/// @brief Recibe el vector de pasajeros, y acumula el total de todos los importes de los vuelos.
///
/// @param list Vector de pasajeros donde se encuentran los datos del precio de vuelo.
/// @param len Tamaño del vector de pasajeros.
/// @return Devuelve el importe total de los vuelos.
float totalImportes(Passenger* list, int len);


/// @brief Recibe el vector de pasajeros, el importe total, y determina el importe promedio por cada pasajero.
///
/// @param list Vector de pasajeros.
/// @param len Tamaño del vector de pasajeros.
/// @param total Total del importe de los vuelos.
/// @return Devuelve el importe promedio de los vuelos.
float promedioImportes(Passenger* list, int len, float total);


/// @brief Recibe el vector de pasajeros, el importe promedio, y determina cuantos pasajeros pagaron mas.
///
/// @param list Vector de pasajeros.
/// @param len Tamaño del vector de pasajeros.
/// @param promedio Importe promedio de los vuelos
/// @return Devuelve la cantidad de pasajeros que pagaron mas del promedio por su vuelo.
int mayorAlPromedio(Passenger* list, int len, float promedio);

#endif
