#include "OtrasFunciones.h"
#include "Operaciones.h"
#include "ArrayPassenger.h"

int menuOpciones(void)
{
	int opcion;

	system("cls");
	printf( "---ADMINISTRADOR DE VUELOS---------------------------------------------------------------------------"
		    "\n\n1. Dar de alta un ticket de Pasajero"
		    "\n2. Modificar un ticket de Pasajero"
			"\n3. Dar de baja un ticket de Pasajero"
			"\n4. Informar:"
			"\n     -Lista de Pasajeros, ordenada alfabéticamente por Apellido y Tipo de pasajero"
			"\n     -Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio"
			"\n     -Lista de Pasajeros ordenada por Código de vuelo y estados de vuelos %cACTIVO%c"
			"\n5. Utilizar datos precargados"
			"\n\n0. Salir"
			"\n-----------------------------------------------------------------------------------------------------", '"', '"');

	opcion=ingresoEntero("\n\nOpcion: ", 0, 5);

	return opcion;
}

int altaTicket(Passenger* list, int len, int pasajeroID)
{
	int id,
		retorno=pasajeroID,
		typePassengerID,
		espacio,
		flyStatusID;

	char name[51],
		 lastName[51],
		 cadenaAux[51],
		 flycode[10];

	float price;

	system("cls");
	printf( "---ALTA DE PASAJEROS----------------------------------------");
	id=pasajeroID+1;

	ingresoCadena("\nIngrese el Nombre del pasajero:\n", cadenaAux, 51);
	strcpy(name,cadenaAux);

	ingresoCadena("\nIngrese el Apellido del pasajero:\n", cadenaAux, 51);
	strcpy(lastName,cadenaAux);

	price=ingresoFloat("\nIngrese el precio del vuelo:\n", 1, 10000000);

	typePassengerID=ingresoEntero("\nIngrese el tipo de pasajero: (1-TURISTA  2-DE NEGOCIOS)\n", 1, 2);

	ingresoCadena("\nIngrese el Codigo de Vuelo:\n", cadenaAux, 10);
	strcpy(flycode,cadenaAux);

	flyStatusID=ingresoEntero("\nIngrese el estado del Vuelo: (1-ACTIVO  2-DEMORADO  3-CANCELADO)\n", 1, 3);

	espacio=addPassenger(list, len, id, name, lastName, price, typePassengerID, flycode, flyStatusID);

	if(espacio==0)
	{
		cargaTiposPasajero(list, len);
		cargaEstados(list, len);

		retorno=pasajeroID+1;
		printf("\n\nTicket cargado correctamente. ID: %d\n",retorno);
	}
	else
	{
		printf("\n\nError al cargar el Ticket, no se ha encontrado espacio libre.\n");
	}

	volverMenu();
	return retorno;
}

void modificarTicket(Passenger* list, int len, int cantTickets)
{
	int idAModificar,
		indiceID;

	if(cantTickets>0)
	{
		idAModificar=ingresoEntero("\n\nIngrese el ID del Ticket que quiera modificar: ", 1, 1000000);
		indiceID=findPassengerById(list, len, idAModificar);
		if(indiceID!=-1)
		{
			short opcion,
				  seguir=1,
				  salir=0;
			char rta[3],
				 cadenaAux[51];

			while(seguir)
			{
				system("cls");
				printf( "---MODIFICAR TICKET-----------------------");
				printf("\nTicket a modificar: ID %d", idAModificar);
				opcion=submenuModificar();
				switch(opcion)
				{
					case NOMBRE:
						ingresoCadena("Ingrese el nuevo Nombre del pasajero: ", cadenaAux, 51);
						strcpy(list[indiceID].name, cadenaAux);
						break;

					case APELLIDO:
						ingresoCadena("Ingrese el nuevo Apellido del pasajero: ", cadenaAux, 51);
						strcpy(list[indiceID].lastName, cadenaAux);
						break;

					case PRECIO:
						list[indiceID].price=ingresoFloat("\nIngrese el nuevo precio del Vuelo:\n", 1, 100000000);
						break;

					case TIPO_PASAJERO:
						list[indiceID].typePassengerID=ingresoEntero("\nIngrese el nuevo Tipo de pasajero:\n", 1, 3);
						break;

					case CODIGO_VUELO:
						ingresoCadena("Ingrese el nuevo Codigo de Vuelo: ", cadenaAux, 10);
						strcpy(list[indiceID].flyInfo.flycode, cadenaAux);
						break;

					case SALIR:
						salir=1;
						volverMenu();
						break;
				}

				if(salir==0)
				{
					printf("\nDesea cambiar algo mas de este Ticket?\n");
					fflush(stdin);
					gets(rta);
					if(rta[0]=='n' && rta[1]=='o')
					{
						seguir=0;
						volverMenu();
					}
				}
			}
		}
		else
		{
			printf("\n\nNo se pudo encontrar el Ticket con ID %d. Volviendo al Menu..\n", idAModificar);
			system("pause");
		}
	}
	else
	{
		errorSinAltas();
	}
}

int bajaTicket(Passenger* list, int len, int cantTickets)
{
	int idABorrar,
		borrado;

	if(cantTickets>0)
	{
		idABorrar=ingresoEntero("\n\nIngrese el ID del Ticket que quiera borrar: ", 1, 1000000);
		borrado=removePassenger(list, len, idABorrar);
		if(borrado!=-1)
		{
			system("cls");
			printf( "---BAJA ALBUM---------------------------------");
			printf("\nEl Ticket con ID %d se ha borrado con exito.", idABorrar);
			cantTickets--;
			volverMenu();
		}
		else
		{
			printf("\n\nNo se pudo encontrar el Ticket con ID %d. Volviendo al Menu..\n", idABorrar);
			system("pause");
		}
	}
	else
	{
		errorSinAltas();
	}

	return cantTickets;
}

void informeTickets(Passenger* list, int len, int cantTickets)
{
	int valido,
		pasajerosMayorAlPromedio;
	float totalImporte,
		  promedioImporte;

	if(cantTickets>0)
	{
		system("cls");
		printf("---LISTADO--------------------------------------------------------------------------------------------------------------------------------------");

		valido=sortPassengers(list, len, 1);
		if(valido==0)
		{
			printf("\n\n1)");
			printPassengers(list, len, 0);
		}
		else
		{
			printf("\n\nError al imprimir el primer listado, revise los datos y reintente.");
		}

		totalImporte=totalImportes(list, len);
		promedioImporte=promedioImportes(list, len, totalImporte);
		pasajerosMayorAlPromedio=mayorAlPromedio(list, len, promedioImporte);
		printf("\n\n2)"
			   "\nTotal del precio de los pasajes: %.2f"
			   "\nPromedio del precio de los pasajes: %.2f"
			   "\nPasajeros que superaron dicho promedio: %d", totalImporte, promedioImporte, pasajerosMayorAlPromedio);

		valido=sortPassengersByCode(list, len, 1);
		if(valido==0)
		{
			printf("\n\n3)");
			printPassengers(list, len, 1);
		}
		else
		{
			printf("\n\nError al imprimir el segundo listado, revise los datos y reintente.");
		}

		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n\nVolviendo al menu..\n");
		system("pause");
	}
	else
	{
		errorSinAltas();
	}
}

int submenuModificar(void)
{
	int opcion;

	printf( "\n\n1. Modificar Nombre del pasajero"
		    "\n2. Modificar Apellido del pasajero"
			"\n3. Modificar Precio del Vuelo"
			"\n4. Modificar Tipo de pasajero"
			"\n5. Modificar Codigo de Vuelo"
			"\n\n0. Salir"
			"\n-----------------------------------------");

	opcion=ingresoEntero("\n\nOpcion: ", 0, 5);

	return opcion;
}

void tablaPasajeros(void)
{
	printf("  ID    |        NOMBRE        |        APELLIDO        |       PRECIO       |      COD. VUELO     |     TIPO PASAJERO    |    ESTADO VUELO    \n");
}

void volverMenu(void)
{
	printf("\n\nVolviendo al Men%c Principal..\n", 163);
	fflush(stdin);
	system("pause");
	fflush(stdin);
}

void errorSinAltas(void)
{
	printf("\nError, no hay Tickets disponibles. Reintente");
	volverMenu();
}
