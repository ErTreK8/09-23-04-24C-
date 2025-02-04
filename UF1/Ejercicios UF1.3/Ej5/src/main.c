#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	//<3 te amo jsjs besis <3//
	int jornada,local,visitante,puntos=0,puntstotal;
	printf("Introduce 10 resultados:\n\n");

	for (int i = 1; i <= 10; i++)
	{
		printf("Jornada Numero:%2d\n",i);
		if (i%2!=0)
		{
			setColor(BLUE);
		}
		printf(" Local: ");
        local=demanarNumero();
		if (i%2!=0)
		{
			setColor(WHITE);
		}
		else{
			setColor(BLUE);
		}
		printf(" Visitante: ");
        visitante=demanarNumero();

		puntstotal+=Partido(&local,&visitante,&i,&puntos);
		
		setColor(WHITE);
		printf("Punts Jornada: %d\n\n",puntos);
	}
	printf("Puntstotal: %d\n\n",puntstotal);

	acabament();
	return 0;
}
