#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BTC 4737679.80

/// @brief Imprime en consola el menu de opciones
///
/// @param km Valor de kilometros que se muestra junto con el menu. Si no se ingresa todavia, se muestra un 0.
/// @param precioAereo Precio del vuelo de Aerolineas que se muestra junto con el menu. Si no se ingresa todavia, se muestra un 0.
/// @param precioLatam Precio del vuelo de Latam que se muestra junto con el menu. Si no se ingresa todavia, se muestra un 0.
/// @return Devuelve la opcion elegida por el usuario.
int menuOpciones(float km, float precioAereo, float precioLatam);

/// @brief Imprime en pantalla un mensaje de error cuando la opcion elegida es invalida.
///
void mensajeError(void);

/// @brief Imprime en consola un mensaje de error si se intentan realizar los calculos antes de cargar todos los datos necesarios.
///
/// @param bkm Bandera de kilometros ingresados. Si es 1 indica que no se cargaron km, y muestra un mensaje de error.
/// @param bAereo Bandera del precio de Aerolineas ingresado. Si es 1 indica que no se cargo el precio, y muestra un mensaje de error.
/// @param bLatam Bandera del precio de Latam ingresado. Si es 1 indica que no se cargo el precio, y muestra un mensaje de error.
void mensajePocosDatos(int bkm, int bAereo, int bLatam);

/// @brief Imprime en consola el menu de opciones de vuelos.
///
/// @return Devuelve la opcion elegida por el usuario.
int menuVuelos(void);

/// @brief Imprime en consola todos los resultados obtenidos, de todos los metodos de pago y sus descuentos/recargos.
///
/// @param indicador Variable que indica si es el comienzo o el fin de la tabla de resultados.
/// @param vuelo Cadena que se imprime junto con la tabla. Puede ser "Aerolineas" o "Latam".
/// @param km Valor de kilometros ingresado.
/// @param precioOriginal Precio base del vuelo.
/// @param debito Precio del vuelo, pagando con tarjeta de debito.
/// @param credito Precio del vuelo, pagando con tarjeta de credito.
/// @param bitcoin Precio del vuelo, pagando con bitcoin.
/// @param unitario Precio de cada km.
/// @param diferencia Diferencia entre los precios de ambos vuelos.
void mostrarResultados(int indicador, char vuelo[], float km, float precioOriginal, float debito, float credito, float bitcoin, float unitario, float diferencia);

/// @brief Imprime en consola un mensaje de error si se intenta mostrar los resultados sin antes haber cargado todos los datos, o sin haber hecho los calculos.
///
void mensajeErrorCuentas(void);

/// @brief Recibe datos precargados, realiza las cuentas, e imprime los resultados.
///
/// @param km Valor de kilometros precargado.
/// @param precioAereo Precio del vuelo de Aerolineas precargado.
/// @param precioLatam Precio del vuelo de Latam precargado.
void hardcodeoDatos(float km, float precioAereo, float precioLatam);

/// @brief Le pregunta al usuario si realmente quiere salir del programa. Imprime el mensaje en consola.
///
/// @return Devuelve la respuesta del usuario (0 si quiere salir, 1 si no).
int mensajeSalir(void);

/// @brief Imprime en consola un mensaje, antes de volver al Menu Principal.
///
void volverMenu(void);

/// @brief Imprime en consola un mensaje, notificando que se realizaron los calculos correctamente.
///
void mensajeCarga(void);

enum
{
	KM=1, PRECIO=2, CALCULO=3, AEREO=1, LATAM=2, RESULTADOS=4, PRECARGA=5, SALIR=6
};

#endif
