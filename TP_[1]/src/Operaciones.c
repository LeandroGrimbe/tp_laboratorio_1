#include "Operaciones.h"
#include "OtrasFunciones.h"

float ingresoFloat(char mensaje[])
{
	int isNum;
	float num;

	printf("%s",mensaje);
	isNum=scanf("%f",&num);

	num=validarNumero(num, isNum, 1, num);

	printf("\nDatos ingresados correctamente");
	volverMenu();

	return num;
}

float validarNumero(float numero, int isNum, int min, int max)
{
	while(isNum!=1 || numero<min || numero>max)
	{
		printf("\nValor inv%clido, reingrese: ", 160);
		fflush(stdin);
		isNum=scanf("%f",&numero);
	}

	return numero;
}

float interesesYDescuentos(float precio, int porcentaje)
{
	float proporcion,
		  precioFinal;

	proporcion=precio*porcentaje/100;

	precioFinal=precio+proporcion;

	return precioFinal;
}

float proporcionBitcoin(float precio, float precioBtc)
{
	float cantBtc;

	cantBtc=precio/precioBtc;

	return cantBtc;
}

float precioPorKm(float precio, float km)
{
	float precioUnitario;

	precioUnitario=precio/km;

	return precioUnitario;
}

float diferenciaVuelos(float precioAereo, float precioLatam)
{
	float diferencia;

	diferencia=precioAereo-precioLatam;
	if(diferencia<0)
	{
		diferencia=diferencia*-1;
	}

	return diferencia;
}
