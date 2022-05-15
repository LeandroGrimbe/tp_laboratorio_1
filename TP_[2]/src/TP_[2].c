#include "OtrasFunciones.h"
#include "Operaciones.h"
#include "ArrayPassenger.h"

int main(void)
{
	int opcion,
		seguir=1,
		pasajeroIDNuevo=0,
		pasajeroIDViejo=0,
		cantTickets=0;

	setbuf(stdout, NULL);

	Passenger pasajeros[LEN];
	initPassengers(pasajeros, LEN);

	while(seguir)
	{
		opcion=menuOpciones();
		switch(opcion)
		{
			case ALTA:
				pasajeroIDNuevo=altaTicket(pasajeros, LEN, pasajeroIDViejo);
				if(pasajeroIDNuevo>pasajeroIDViejo)
				{
					pasajeroIDViejo=pasajeroIDNuevo;
					cantTickets++;
				}
				break;

			case MODIFICAR:
				modificarTicket(pasajeros, LEN,cantTickets);
				break;

			case BAJA:
				cantTickets=bajaTicket(pasajeros, LEN, cantTickets);
				break;

			case INFORMAR:
				informeTickets(pasajeros, LEN, cantTickets);
				break;

			case HARDCODEO:
				hardcodeoPasajeros(pasajeros, LEN);
				cantTickets=6;
				pasajeroIDViejo=6;
				break;

			case SALIR:
				seguir=0;
				break;
		}
	}
}
