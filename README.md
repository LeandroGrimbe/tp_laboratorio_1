# TP1 - Calculadora de Costos de Vuelos

## Descripción
Este proyecto es una aplicación desarrollada en **C** para calcular y comparar los costos de vuelos de **Latam** y **Aerolíneas Argentinas**, ofreciendo distintas opciones de pago a los clientes.

## Funcionalidades
- **Ingreso de datos:**
  - Cantidad de kilómetros del vuelo.
  - Precio de los vuelos de Latam y Aerolíneas Argentinas.
- **Cálculo de costos con diferentes métodos de pago:**
  - **Tarjeta de débito:** 10% de descuento.
  - **Tarjeta de crédito:** 25% de interés.
  - **Bitcoin:** Conversión basada en 1 BTC = 4,606,954.55 ARS.
  - **Precio unitario por km.**
  - **Diferencia de precio entre ambas aerolíneas.**
- **Visualización de resultados:**
  - Se presentan los valores calculados en el formato solicitado.
- **Carga forzada de datos:**
  - Utiliza valores predefinidos para pruebas rápidas.
- **Validación de datos:**
  - No permite realizar cálculos sin haber ingresado información previa.



# TP2 - Gestión de Pasajeros de una Aerolínea

## Descripción
Este proyecto es una aplicación desarrollada en **C** para administrar los pasajeros de una aerolínea, permitiendo el alta, modificación, baja y consulta de pasajeros, con validaciones y organización eficiente de datos.

## Funcionalidades
- **Alta de pasajeros:**
  - Generación automática de ID.
  - Ingreso de nombre, apellido, precio del pasaje, tipo de pasajero y código de vuelo.
- **Modificación de pasajeros:**
  - Permite modificar nombre, apellido, precio del pasaje, tipo de pasajero y código de vuelo.
- **Baja de pasajeros:**
  - Eliminación lógica del pasajero mediante su ID.
- **Informes:**
  - Listado de pasajeros ordenado por apellido y tipo de pasajero.
  - Cálculo del total y promedio de precios, indicando cuántos pasajeros superan el precio promedio.
  - Listado de pasajeros por código de vuelo y estado de vuelo 'ACTIVO'.



# TP3 - Gestión de Pasajeros con LinkedList

## Descripción
Este proyecto es una aplicación desarrollada en **C** para administrar los pasajeros de una aerolínea, utilizando **LinkedList** para la gestión dinámica de memoria y el almacenamiento eficiente de datos.

## Funcionalidades
- **Carga de datos desde archivos:**
  - Importación de pasajeros desde un archivo `data.csv` en modo texto.
  - Importación de pasajeros desde un archivo `data.csv` en modo binario.
- **Gestión de pasajeros:**
  - Alta de nuevos pasajeros con generación automática de ID.
  - Modificación de datos de un pasajero existente.
  - Eliminación de pasajeros.
- **Listado y ordenamiento:**
  - Mostrar la lista completa de pasajeros.
  - Ordenar pasajeros por distintos criterios.
- **Guardado de datos:**
  - Exportación de pasajeros a un archivo `data.csv` en modo texto.
  - Exportación de pasajeros a un archivo `data.csv` en modo binario.
- **Validaciones y restricciones:**
  - No se puede salir del programa sin haber guardado los cambios.
  - Los IDs de los pasajeros deben ser únicos y no reutilizarse después de una eliminación.



# TP4 - Biblioteca LinkedList

## Descripción
Este proyecto consiste en el desarrollo de una biblioteca en **C** implementando una estructura de datos LinkedList, y en una aplicacion para darle uso a ella.

## Funcionalidades
*   **Creación y manipulación de LinkedList:**
    *   Creación de una nueva LinkedList.
    *   Obtención del tamaño de la LinkedList.
    *   Obtención de un nodo específico por índice.
    *   Agregar un nodo en una posición específica.
    *   Agregar un elemento al final de la LinkedList.
    *   Obtención de un elemento por índice.
    *   Modificación de un elemento en un índice específico.
    *   Eliminación de un elemento por índice.
    *   Eliminación de todos los elementos de la LinkedList.
    *   Eliminación de la LinkedList completa.
    *   Obtención del índice de la primera aparición de un elemento.
    *   Verificación si la LinkedList está vacía.
    *   Inserción de un elemento en una posición específica, desplazando los demás.
    *   Eliminación y retorno del elemento en un índice específico.
    *   Verificación de la existencia de un elemento.
    *   Verificación si todos los elementos de una LinkedList están contenidos en otra.
    *   Obtención de una sublista de la LinkedList.
    *   Creación de una copia de la LinkedList.
    *   Ordenamiento de los elementos de la LinkedList mediante una función de comparación.
