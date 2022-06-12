#include "OtherFunctions.h"

int optionMenu(void)
{
	int option;

	system("cls");
	puts( "---LISTA DE PASAJEROS----------------------------------------------------------------------------"
			"\n\n1. Cargar datos del archivo -data.csv- (modo texto)"
			"\n2. Cargar datos del archivo -data.csv- (modo binario)"
		    "\n3. Alta de Pasajero"
		    "\n4. Modificar datos de un Pasajero"
			"\n5. Baja de Pasajero"
			"\n6. Listado"
			"\n7. Ordenar Pasajeros"
			"\n8. Guardar los datos en el archivo -data.csv- (modo texto)"
			"\n9. Guardar los datos en el archivo -data.csv- (modo binario)"
			"\n\n10. Salir"
			"\n-------------------------------------------------------------------------------------------------");

	option=intImput("\n\nOpcion: ", 1, 10);

	return option;
}

int sortMenu(void)
{
	int option;
	puts( 	"Ingrese el criterio por el cual quiere ordenar la lista: "
			"\n\n0. ID"
			"\n1. NOMBRE"
		    "\n2. APELLIDO"
		    "\n3. PRECIO"
			"\n4. CODIGO DE VUELO"
			"\n5. TIPO DE PASAJERO"
			"\n6. ESTADO DE VUELO"
			"\n\n7. Salir"
			"\n-------------------------------------------------------------------------------------------------");

	option=intImput("\n\nOpcion: ", 0, 7);

	return option;
}

int exitMenu(int binSaveFlag, int txtSaveFlag)
{
	int option=11,
		stay=1;
	char answer[3];

	if(!binSaveFlag && !txtSaveFlag)
		puts("\n\nTodavia no se han guardado los datos en ningun archivo. Si realizo algun cambio, lo perdera al salir.");
	else if(binSaveFlag && !txtSaveFlag)
		puts("\n\nTodavia no se han guardado los datos en el archivo de texto.");
	else if(!binSaveFlag && txtSaveFlag)
		puts("\n\nTodavia no se han guardado los datos en el archivo binario.");

	puts ("Esta seguro que desea salir?");
	fflush(stdin);
	gets(answer);
	if(toupper(answer[0])=='S' && toupper(answer[1])=='I')
	{
		stay=0;
		option=10;
	}

	if(stay==0)
	{
		exitMessage();
	}
	return option;
}

void exitMessage(void)
{
	system("cls");
	puts("                     $$$");
	delay(0.05);
	puts("                    $___$");
	delay(0.05);
	puts("                     $$$");
	delay(0.05);
	puts("                     $_$");
	delay(0.05);
	puts("                     $_$");
	delay(0.05);
	puts("                   $$$_$$$");
	delay(0.05);
	puts("                 $$__$$$__$$$");
	delay(0.05);
	puts("               $$__$$$$$$$___$");
	delay(0.05);
	puts("              $_______________$");
	delay(0.05);
	puts("             $_________________$");
	delay(0.05);
	puts("             $_________________$");
	delay(0.05);
	puts("             $_____$$$$$$$$$$$$$$$");
	delay(0.05);
	puts("             $____$_______________$");
	delay(0.05);
	puts("             $____$___$$$$$$$$$$$$$");
	delay(0.05);
	puts("             $___$___$___________$$$");
	delay(0.05);
	puts("             $___$___$_$$$___$$$__$$");
	delay(0.05);
	puts("             $___$___$_$$$___$$$__$$");
	delay(0.05);
	puts("             $___$___$___________$$$");
	delay(0.05);
	puts("             $____$___$$$$$$$$$$$$$");
	delay(0.05);
	puts("             $_____$$$$$$$$$$$$$$");
	delay(0.05);
	puts("             $_________________$");
	delay(0.05);
	puts("             $____$$$$$$$$$$$$$$");
	delay(0.05);
	puts("             $___$__$__$__$__$");
	delay(0.05);
	puts("             $__$$$$$$$$$$$$$$");
	delay(0.05);
	puts("             $__$___$__$__$__$");
	delay(0.05);
	puts("             $___$$$$$$$$$$$$$$$");
	delay(0.05);
	puts("            $$$_________________$$$");
	delay(0.05);
    puts("          $$___$$$_________$$$$$___$$");
    delay(0.05);
    puts("        $$________$$$$$$$$$__________$$$");
    delay(0.05);
    puts("       $__$$_____________________$$$$___$$");
    delay(0.05);
    puts("   $$$$$___$$$$$$$$______$$$$$$$_______$_$");
    delay(0.05);
    puts("  $______$$_________$$$$$$______________$_$$");
    delay(0.05);
    puts(" $____$____$____________________________$_$_$");
    delay(0.05);
    puts(" $_____$___$______________$$$$$$$$$$$___$_$_$$");
    delay(0.05);
    puts(" $$$____$___$__$$$$$$$$$$$$__________$___$_$_$$");
    delay(0.05);
    puts("$___$$$$____$__$_____________________$___$_$$_$");
    delay(0.05);
    puts("$$$____$___$$__$_____________________$$__$_$__$");
    delay(0.05);
    puts("$___$__$__$$___$______________________$__$$$__$");
    delay(0.05);
    puts("$_____$$_$$____$_______________$$$____$__$_$__$");
    delay(0.3);
    puts("\n\n                     ADIOS");
    delay(2.3);
}

void delay(float number_of_seconds)
{
    float milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

