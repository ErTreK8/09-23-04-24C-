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
	int opcio;
	//if(existeixFitxer(UBICACIOPILOT)) remove(UBICACIOPILOT);
	do
	{
		cls();
		opcio = preguntaOpcio();
		switch (opcio)
			{
			case AFEGIR:
				inserirPilot();
				break;

			case MISSIO:
				inserirMissio();
				break;
			
			case RETORN:
				retornaMissio();
				break;
			
			case MOSTRAPILOT:	
				mostrarPilot();
				break;
			case MOSTRAMISSIO:
				mostraPilotsMissio();
				break;
			
			case SORTIR: printf("\nAdeu");
				break;
			}
	
	} while (opcio != SORTIR);
	

	acabament();
	return 0;
}
