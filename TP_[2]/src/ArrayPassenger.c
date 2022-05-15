#include "OtrasFunciones.h"
#include "Operaciones.h"
#include "ArrayPassenger.h"

int initPassengers(Passenger* list,
				   int len)
{
	int retorno=-1;

	if(list!=NULL && len>0 && len<2001)
	{
		int i;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}
		retorno=0;
	}

	return retorno;
}

int addPassenger(Passenger* list,
				 int len,
				 int id,
				 char name[],
				 char lastName[],
				 float price,
				 int typePassengerID,
				 char flycode[],
				 int flyStatusID)
{
	int retorno=-1;

	if(list!=NULL && len>0 && len<2001)
	{
		int i;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				list[i].id=id;
				list[i].price=price;
				list[i].typePassengerID=typePassengerID;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				strcpy(list[i].flyInfo.flycode ,flycode);
				list[i].flyInfo.flyStatusID=flyStatusID;
				list[i].isEmpty=0;

				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int findPassengerById(Passenger* list,
					  int len,
					  int id)
{
	int retorno=-1;

	if(list!=NULL && len>0 && len<2001)
	{
		int i;
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger* list,
					int len,
					int id)
{
	int retorno=-1;

	if(list!=NULL && len>0 && len<2001)
	{
		int i;
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				list[i].isEmpty=1;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int sortPassengers(Passenger* list,
				   int len,
				   int order)
{
	int retorno=-1;

	if(list!=NULL && len>0 && len<2001)
	{
		retorno=0;
		int i,j;
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty==0 && list[j].isEmpty==0)
				{
					if(order==1)
					{
						if(strcmp(list[i].lastName,list[j].lastName)>0)
						{
							cambioArray(list, i, j);
						}
						else if(strcmp(list[i].lastName,list[j].lastName)==0)
						{
							if(strcmp(list[i].typePassenger,list[j].typePassenger)>0)
							{
								cambioArray(list, i, j);
							}
						}
					}
					else if(order==0)
					{
						if(strcmp(list[i].lastName,list[j].lastName)<0)
						{
							cambioArray(list, i, j);
						}
						else if(strcmp(list[i].lastName,list[j].lastName)==0)
						{
							if(strcmp(list[i].typePassenger,list[j].typePassenger)<0)
							{
								cambioArray(list, i, j);
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}

int printPassengers(Passenger* list, int length, int soloActivos)
{
	tablaPasajeros();
	int i;
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==0)
		{
			if(soloActivos==0)
			{
				printf("\n%4d   %17s  %20s   %20.2f           %10s             %15s        %15s",
						list[i].id, list[i].name, list[i].lastName,
						list[i].price, list[i].flyInfo.flycode, list[i].typePassenger,
						list[i].flyInfo.flyStatus);
			}
			else if(list[i].flyInfo.flyStatusID==1 && soloActivos)
			{
				printf("\n%4d   %17s  %20s   %20.2f           %10s             %15s        %15s",
						list[i].id, list[i].name, list[i].lastName,
						list[i].price, list[i].flyInfo.flycode, list[i].typePassenger,
						list[i].flyInfo.flyStatus);
			}
		}
	}

	return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno=-1;

	if(list!=NULL && len>0 && len<2001)
	{
		retorno=0;
		int i,j;
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].isEmpty==0 && list[j].isEmpty==0)
				{
					if(order==1)
					{
						if(strcmp(list[i].flyInfo.flycode,list[j].flyInfo.flycode)>0)
						{
							cambioArray(list, i, j);
						}
						else if(strcmp(list[i].flyInfo.flycode,list[j].flyInfo.flycode)==0)
						{
							if(list[i].flyInfo.flyStatusID>list[j].flyInfo.flyStatusID)
							{
								cambioArray(list, i, j);
							}
						}
					}
					else if(order==0)
					{
						if(strcmp(list[i].flyInfo.flycode,list[j].flyInfo.flycode)<0)
						{
							cambioArray(list, i, j);
						}
						else if(strcmp(list[i].flyInfo.flycode,list[j].flyInfo.flycode)==0)
						{
							if(list[i].flyInfo.flyStatusID<list[j].flyInfo.flyStatusID)
							{
								cambioArray(list, i, j);
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}

