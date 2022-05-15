#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LEN 2000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	char flycode[10];
	char flyStatus[15];
	int flyStatusID;
}Vuelo;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	Vuelo flyInfo;
	int typePassengerID;
	char typePassenger[15];
	int isEmpty;
}Passenger;

int initPassengers(Passenger* list,
				   int len);

int addPassenger(Passenger* list,
				 int len,
				 int id,
				 char name[],
				 char lastname[],
				 float price,
				 int typePassengerID,
				 char flycode[],
				 int flyStatusID);

int findPassengerById(Passenger* list,
					  int len,
					  int id);

int removePassenger(Passenger* list,
					int len,
					int id);

int sortPassengers(Passenger* list,
				   int len,
				   int order);

int printPassengers(Passenger* list,
					int lengh,
					int soloActivos);

int sortPassengersByCode(Passenger* list,
						 int len,
						 int order);

#endif
