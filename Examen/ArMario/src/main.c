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
	
	DISFRESSA armari[MAXARMARI];



	int opcio;
	setColor(WHITE);

	printf("Presiona enter para empezar el programa");
	getch();
	cls();

	vuidaArmari(armari);

	do
	{
		cls();
		opcio = preguntaOpcio();
		switch (opcio)
			{
			case AFEGIRDISFRESSA:
				inserirDisfressa(armari);
				break;
			case MOSTRADISFRESSA:
				mostraArmari(armari);
				break;
			case AFEGIRVALORACIO:
				insertaValoracions(armari);
				break;
			case BAIXADISFRESSA:
				donarBaixaDisfressa(armari);
				break;
			case SORTIR:
			
				break;
			}	
		getch();
		cls();
	} while (opcio != SORTIR);
	acabament();
	return 0;
}
