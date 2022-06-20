#include "Operaciones.h"
#include "OtrasFunciones.h"

int main()
{
	int opcion,
		empresa,
		seguir=1,
		datos=0,
		banderaKm=1,
		banderaAereo=1,
		banderaLatam=1;

	float km=0,
		  precioAereo=0,
		  precioLatam=0,
		  diferenciaPrecio,

		  debitoAereo,
		  creditoAereo,
		  btcAereo,
		  unitarioAereo,

		  debitoLatam,
		  creditoLatam,
		  btcLatam,
		  unitarioLatam;

	setbuf(stdout, NULL);

	while(seguir)
	{
		opcion=menuOpciones(km, precioAereo, precioLatam);
		switch(opcion)
		{
			case KM:
				km=ingresoFloat("\nIngrese los kilometros: ");
				datos=0;
				banderaKm=0;
			break;

			case PRECIO:
				empresa=menuVuelos();
				switch(empresa)
				{
					case AEREO:
						precioAereo=ingresoFloat("\nIngrese el precio del vuelo con Aerolineas: ");
						datos=0;
						banderaAereo=0;
					break;

					case LATAM:
						precioLatam=ingresoFloat("\nIngrese el precio del vuelo con Latam: ");
						datos=0;
						banderaLatam=0;
					break;

					default:
						mensajeError();
					break;
				}
			break;

			case CALCULO:
				if(banderaKm==0 && banderaAereo==0 && banderaLatam==0)
				{
					debitoAereo=interesesYDescuentos(precioAereo, -10); //10% de descuento
					creditoAereo=interesesYDescuentos(precioAereo, 25); //25% de interes
					btcAereo=proporcionBitcoin(precioAereo, BTC);
					unitarioAereo=precioPorKm(precioAereo, km);

					debitoLatam=interesesYDescuentos(precioLatam,-10); //10% de descuento
					creditoLatam=interesesYDescuentos(precioLatam,25); //25% de interes
					btcLatam=proporcionBitcoin(precioLatam,BTC);
					unitarioLatam=precioPorKm(precioLatam, km);

					diferenciaPrecio=diferenciaVuelos(precioAereo, precioLatam);

					datos=1; //Verificador para la funcion mostrarResultados
					mensajeCarga();
				}
				else
				{
					mensajePocosDatos(banderaKm, banderaAereo, banderaLatam);
				}
			break;

			case RESULTADOS:
				if(datos)
				{
					mostrarResultados(1, "Aerolineas", km, precioAereo, debitoAereo, creditoAereo, btcAereo, unitarioAereo, diferenciaPrecio);
					mostrarResultados(0, "Latam", km, precioLatam, debitoLatam, creditoLatam, btcLatam, unitarioLatam, diferenciaPrecio);
				}
				else
				{
					mensajeErrorCuentas();
				}
			break;

			case PRECARGA:
				hardcodeoDatos(7090, 162965, 159339); //parametros del enunciado
			break;

			case SALIR:
				seguir=mensajeSalir();
			break;

			default:
				mensajeError();
			break;
		}

	}
}
