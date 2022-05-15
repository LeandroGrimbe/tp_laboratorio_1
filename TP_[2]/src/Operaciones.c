#include "OtrasFunciones.h"
#include "Operaciones.h"
#include "ArrayPassenger.h"

int ingresoEntero(char mensaje[50], int min, int max)
{
	int isNum;
	int num;

	printf("%s",mensaje);
	isNum=scanf("%d",&num);

	while(isNum!=1 || num<min || num>max)
	{
		printf("\nValor inv%clido, reingrese: ", 160);
		fflush(stdin);
		isNum=scanf("%d",&num);
	}

	return num;
}

float ingresoFloat(char mensaje[50], int min, int max)
{
	int isNum;
	float num;

	printf("%s",mensaje);
	isNum=scanf("%f",&num);

	while(isNum!=1 || num<min || num>max)
	{
		printf("\nValor inv%clido, reingrese: ", 160);
		fflush(stdin);
		isNum=scanf("%f",&num);
	}

	return num;
}

void ingresoCadena(char mensaje[50], char cadenaAux[], int cadenaLen)
{
	char cadena[cadenaLen];

	printf("\n%s", mensaje);
	fflush(stdin);
	gets(cadena);

	while(strlen(cadena)>cadenaLen)
	{
		printf("\nSe ha excedido el limite, reingrese: ");
		gets(cadena);
	}

	int i;
	for(i=0;i<cadenaLen;i++)
	{
		cadena[i]=toupper(cadena[i]);
	}

	strcpy(cadenaAux,cadena);
}

void cambioArray(Passenger* list, int indice1, int indice2)
{
	Passenger aux;

	aux=list[indice1];
	list[indice1]=list[indice2];
	list[indice2]=aux;
}

void cargaEstados(Passenger* list, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			if(list[i].flyInfo.flyStatusID==1)
			{
				strcpy(list[i].flyInfo.flyStatus, "ACTIVO");
			}
			else if(list[i].flyInfo.flyStatusID==2)
			{
				strcpy(list[i].flyInfo.flyStatus, "DEMORADO");
			}
			else if(list[i].flyInfo.flyStatusID==3)
			{
				strcpy(list[i].flyInfo.flyStatus, "CANCELADO");
			}
		}
	}
}

void cargaTiposPasajero(Passenger* list, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			if(list[i].typePassengerID==1)
			{
				strcpy(list[i].typePassenger, "TURISTA");
			}
			else if(list[i].typePassengerID==2)
			{
				strcpy(list[i].typePassenger, "DE NEGOCIOS");
			}
		}
	}
}

void hardcodeoPasajeros(Passenger* list, int len)
{
	Passenger datos[6]={{1, "SEBASTIAN", "RODRIGUEZ", 4500, {"2031", "ACTIVO", 1}, 1, "TURISTA", 0},
						{2, "JOAQUIN", "PEREZ", 7600, {"2384", "DEMORADO", 2}, 1, "TURISTA", 0},
						{3, "MANUEL", "GONZALEZ", 3900, {"2995", "CANCELADO", 3}, 1, "DE NEGOCIOS", 0},
						{4, "PEPE", "RODRIGUEZ", 4800, {"2384", "DEMORADO", 2}, 1, "TURISTA", 0},
						{5, "HORACIO", "QUIROGA", 10500, {"2391", "ACTIVO", 1}, 1, "DE NEGOCIOS", 0},
						{6, "LIONEL", "MESSI", 8210, {"2031", "ACTIVO", 1}, 1, "DE NEGOCIOS", 0}};

	initPassengers(list, len); //Limpio el array si ya hay datos cargados

	int i;
	for(i=0;i<6;i++)
	{
		list[i]=datos[i];
	}

	printf("\n\nDatos cargados con exito.");
	volverMenu();
}

float totalImportes(Passenger* list, int len)
{
	float total=0;
	int i;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			total+=list[i].price;
		}
	}

	return total;
}

float promedioImportes(Passenger* list, int len, float total)
{
	float promedio;
	int pasajeros=0,
		i;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			pasajeros++;
		}
	}

	promedio=total/pasajeros;

	return promedio;
}

int mayorAlPromedio(Passenger* list, int len, float promedio)
{
	int i,
		pasajerosMayorAlPromedio=0;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0 && list[i].price > promedio)
		{
			pasajerosMayorAlPromedio++;
		}
	}

	return pasajerosMayorAlPromedio;
}


