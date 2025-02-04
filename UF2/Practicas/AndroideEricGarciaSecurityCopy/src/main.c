#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	//1252 coje codigos distintos no como el UTF_8 i akgi asu¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	
	// MAXANDROIDE es 20

	TIPOANDROIDE tipo[MAXANDROIDE];
	int qttTipo=0;

	ANDROIDE droid[MAXANDROIDE];
	int qttDroid=0;

	CAMP campo[MAXANDROIDE];
	int qttCampo=0;

	int opcio;
	setColor(WHITE);
	printf("Presiona enter para empezar el programa");
	getch();
	cls();
	pintaCapsalera();

	do
	{
		cls();
		opcio = preguntaOpcio();
		switch (opcio)
			{
			case AFEGIRANDROIDE:
				if (qttTipo<MAXANDROIDE)
				{
					insertTipo(tipo, &qttTipo);
				}
				else
				{
					printf("Maximo de tipos introducidos");
				}
				
				break;
			case INSERTARANDROIDE:
				if (qttTipo==0)
				{
					printf("Per inserir un Androide primer crea un Tipus d'Andoride");
				}
				else if (qttDroid<MAXANDROIDE)
				{
					printaTipus(tipo,qttTipo);
					insertDroid(droid,&qttDroid,tipo,qttTipo);
				}
				else
				{
					printf("Maximo de androides introducidos");
				}				
				break;
			case MOSTRARANDROIDE:
				printDroid(droid,qttDroid);
				break;
			case INSERTARCAMP:
				if (qttCampo<MAXANDROIDE)
				{
					insertCamp(campo,&qttCampo);
				}
				else
				{
					printf("Maximo de campos introducidos");
				}
				break;
			case MOSTRARCAMP:
				if (qttCampo==0)
				{
					setColor(RED);
					printf("No hay Campos Inseridos");
					setColor(WHITE);
				}
				else
				{
					mostrarCamps(campo,qttCampo);
					Sleep(2000);
				}
				break;
			case JORNADA:
				if (qttCampo==0 || qttDroid==0)
				{
					printf("Introduce un campo/Androide antes de hacer la jornada");
				}
				else joranada(campo,&qttCampo,droid,&qttDroid);
				break;
			case SORTIR:
				break;
			}	
		Sleep(2000);
	} while (opcio != SORTIR);
	

	acabament();
	return 0;
}
