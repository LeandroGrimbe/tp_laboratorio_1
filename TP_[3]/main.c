#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    setbuf(stdout,NULL);

    LinkedList* passengerList = ll_newLinkedList();
    char pathAux[100];
    int option,
		binSaveFlag=0,
		txtSaveFlag=0,
		loadFlag=0;

    do{
    	option=optionMenu();
        switch(option)
        {
            case LOAD_TEXT:
            	if(loadFlag==0)
            	{
            		if(controller_loadFromText(getPath(pathAux, 1, "CSV"),passengerList)==0)
            			loadFlag=1;
            	}
            	else
            		puts("\nArchivo ya cargado. ...");
                break;

            case LOAD_BIN:
            	if(loadFlag==0)
            	{
					if(controller_loadFromBinary(getPath(pathAux, 1, "BIN"), passengerList)==0)
						loadFlag=1;
				}
				else
					puts("\nArchivo ya cargado. ...");
            	break;

            case ADD:
            	controller_addPassenger(passengerList);
            	break;

            case MODIFY:
            	if(ll_isEmpty(passengerList)==0)
            		controller_editPassenger(passengerList);
            	else
            		puts("\nTodavia no se ha cargado ningun pasajero, no es posible realizar esta accion.");
            	break;

            case REMOVE:
            	if(ll_isEmpty(passengerList)==0)
					controller_removePassenger(passengerList);
            	else
            		puts("\nTodavia no se ha cargado ningun pasajero, no es posible realizar esta accion.");
            	break;

            case LIST:
            	if(ll_isEmpty(passengerList)==0)
            		controller_ListPassenger(passengerList);
            	else
            		puts("\nNo es posible mostrar el listado, todavia no se ha cargado ningun pasajero.");
            	break;

            case SORT:
            	if(ll_isEmpty(passengerList)==0)
            		controller_sortPassenger(passengerList);
            	else
            		puts("\nNo es posible ordenar la lista, se han cargado menos de dos pasajeros.");
            	break;

            case SAVE_TEXT:
            	if(ll_isEmpty(passengerList)==0)
            	{
					if(controller_saveAsText(getPath(pathAux, 2, "CSV"), passengerList)==0)
						txtSaveFlag=1;
            	}
            	else
            		puts("\nNo es posible guardar el archivo, todavia no se ha cargado ningun pasajero.");
            	break;

            case SAVE_BIN:
            	if(ll_isEmpty(passengerList)==0)
            	{
					if(controller_saveAsBinary(getPath(pathAux, 2, "BIN"), passengerList)==0)
						binSaveFlag=1;
            	}
            	else
            		puts("\nNo es posible guardar el archivo, todavia no se ha cargado ningun pasajero.");
            	break;

            case EXIT:
            	option = exitMenu(binSaveFlag, txtSaveFlag);
            	break;
        }
        if(option!=10)
        {
        	puts("\nVolviendo al Menu...");
        	system("\npause");
        }
    }while(option != 10);
}
