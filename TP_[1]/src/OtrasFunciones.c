#include "OtrasFunciones.h"
#include "Operaciones.h"

int menuOpciones(float km, float precioAereo, float precioLatam)
{
	int opcion;

	system("cls");
	printf( "---CALCULADORA DE COSTOS------------------------------------------------------"
		    "\n\n1. Ingreso de Kil%cmetros (Km=%.2f)"
		    "\n2. Ingreso del Precio de los Vuelos (Aerol%cneas=%.2f, Latam=%.2f)"
			"\n3. C%clculo de costos"
			"\n     -Tarjeta de d%cbito (descuento 10%c)"
			"\n     -Tarjeta de cr%cdito (inter%cs 25%c)"
			"\n     -Bitcoin"
			"\n     -Precio por km"
			"\n     -Diferencia de precios (Latam - Aerol%cneas)"
			"\n4. Mostrar resultados"
			"\n5. Carga forzada de datos (Km=7090, Aerol%cneas=162965, Latam=159339)"
			"\n6. Salir"
			"\n------------------------------------------------------------------------------"
			"\n\nOpci%cn: ", 162, km, 161, precioAereo, precioLatam, 160, 130, '%', 130, 130, '%', 161, 161, 162);

	scanf("%d",&opcion);

	return opcion;
}

void mensajeError(void)
{
	printf("\nOpci%cn inv%clida", 162, 160);
	volverMenu();
}

void mensajePocosDatos(int bKm, int bAereo, int bLatam)
{
	char mensajeKm[]="Error, falta ingresar los KM";
	char mensajeAereo[]="Error, falta ingresar el precio del vuelo de Aerolineas";
	char mensajeLatam[]="Error, falta ingresar el precio del vuelo de Latam";

	if(bKm==0)
	{
		strcpy(mensajeKm,".");
	}
	if(bAereo==0)
	{
		strcpy(mensajeAereo,".");
	}
	if(bLatam==0)
	{
		strcpy(mensajeLatam,".");
	}

	printf("\n\n%s\n%s\n%s", mensajeKm, mensajeAereo, mensajeLatam);
	volverMenu();
}

int menuVuelos(void)
{
	int opcion,
		isNum;

	printf( "\n\n*PRECIOS DE VIAJE*"
		    "\n\n1. Vuelo Aerol%cneas"
		    "\n2. Vuelo Latam"
			"\n\nOpci%cn: ", 161, 162);

	isNum=scanf("%d",&opcion);
	opcion=validarNumero(opcion, isNum, 1, 2);

	return opcion;
}

void mostrarResultados(int indicador, char vuelo[], float km, float precioOriginal, float debito, float credito, float bitcoin, float unitario, float diferencia)
{
	if(indicador)
	{
		printf("\n---RESULTADOS-----------------------"
			   "\nKil%cmetros Ingresados: %.2f", 162, km);
	}

	printf("\n\n%s: %.2f"
		   "\na)Precio con tarjeta de d%cbito: %.2f"
		   "\nb)Precio con tajeta de cr%cdito: %.2f"
		   "\nc)Precio en Bitcoin: %.7f"
		   "\nd)Precio unitario: %.2f", vuelo, precioOriginal, 130, debito, 130, credito, bitcoin, unitario);

	if(!indicador)
	{
		printf("\n\nLa diferencia de precio es: %.2f", diferencia);
		volverMenu();
	}
}

void mensajeErrorCuentas(void)
{
	printf("\n\nError, faltan datos, o no se han realizado los c%clculos", 160);
	volverMenu();
}

void hardcodeoDatos(float km, float precioAereo, float precioLatam)
{
	float diferenciaPrecio,

		  debitoAereo,
		  creditoAereo,
		  btcAereo,
		  unitarioAereo,

		  debitoLatam,
		  creditoLatam,
		  btcLatam,
		  unitarioLatam;

	debitoAereo=interesesYDescuentos(precioAereo, 25); //25% de interes
	creditoAereo=interesesYDescuentos(precioAereo, -10); //10% de descuento
	btcAereo=proporcionBitcoin(precioAereo, BTC);
	unitarioAereo=precioPorKm(precioAereo, km);

	debitoLatam=interesesYDescuentos(precioLatam,25); //25% de interes
	creditoLatam=interesesYDescuentos(precioLatam,-10); //10% de descuento
	btcLatam=proporcionBitcoin(precioLatam,BTC);
	unitarioLatam=precioPorKm(precioLatam, km);

	diferenciaPrecio=diferenciaVuelos(precioAereo, precioLatam);

	mostrarResultados(1, "Aerolineas", km, precioAereo, debitoAereo, creditoAereo, btcAereo, unitarioAereo, diferenciaPrecio);
	mostrarResultados(0, "Latam", km, precioLatam, debitoLatam, creditoLatam, btcLatam, unitarioLatam, diferenciaPrecio);
}


int mensajeSalir(void)
{
	char rta;
	int retorno;

	printf("\n\nSeguro que desea salir? (s/n)"
			"\nRespuesta: ");

	fflush(stdin);
	scanf("%c", &rta);
	while(rta!='s' && rta!='n')
	{
		printf("\nRespuesta inv%clida, reingrese: ",160);
		fflush(stdin);
		scanf("%c", &rta);
	}

	if(rta=='n')
	{
		retorno=1;
		volverMenu();
	}
	else
	{
		retorno=0;
	}

	return retorno;
}

void volverMenu(void)
{
	printf("\n\nVolviendo al Men%c Principal..\n", 163);
	fflush(stdin);
	system("pause");
	fflush(stdin);
}

void mensajeCarga(void)
{
	printf("\n\nSe han realizado los c%clculos con %cxito", 160, 130);
	volverMenu();
}
