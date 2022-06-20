#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Pide un numero flotante por teclado.
///
/// @param mensaje Cadena que corresponde a la pregunta que se le desea imprimir en consola al usuario.
/// @return Devuelve el valor ingresado por el usuario, ya validado.
float ingresoFloat(char mensaje[]);

/// @brief Recibe un valor y lo valida, segun las condiciones recibidas.
///
/// @param numero Valor recibido a validar.
/// @param isNum Indicador de si lo que se recibe es realmente un entero (si es 1, es un entero, caso contrario, es otro simbolo).
/// @param min Valor minimo que puede tomar el numero recibido. Si es menor, se pide reingresarlo.
/// @param max Valor maximo que puede tomar el numero recibido. Si es mayor, se pide reingresarlo.
/// @return Devuelve el numero validado.
int validarEntero(int numero, int isNum, int min, int max);

/// @brief Calcula el precio con interes o descuento, segun el porcentaje recibido.
///
/// @param precio Precio base al cual aplicar descuento/interes.
/// @param porcentaje porcentaje que se le desea descontar o sumar al precio base (Si es positivo, es un interes, si es negativo, es un descuento).
/// @return Devuelve el precio final.
float interesesYDescuentos(float precio, int porcentaje);

/// @brief Calcula cuanto saldria el vuelo si se pagara en Bitcoin.
///
/// @param precio Precio del vuelo.
/// @param precioBtc Precio actual del bitcoin.
/// @return Devuelve la cantidad de Bitcoin equivalente al precio del vuelo.
float proporcionBitcoin(float precio, float precioBtc);

/// @brief Calcula cuanto saldria cada kilometro a recorrer.
///
/// @param precio Precio total del vuelo.
/// @param km Cantidad de kilometros del vuelo.
/// @return Devuelve el precio equivalente a cada kilometro del viaje.
float precioPorKm(float precio, float km);

/// @brief Calcula la diferencia de precio entre ambos vuelos
///
/// @param precioAereo Precio del vuelo con Aerolineas.
/// @param precioLatam Precio del vuelo con Latam.
/// @return Devuelve la diferencia de precio entre Aerolineas y Latam.
float diferenciaVuelos(float precioAereo, float precioLatam);

#endif
