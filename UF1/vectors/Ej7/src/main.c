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
	int qttV1, qttV2;
	int v1[MAXVECTOR1];
	int v2[MAXVECTOR2];

	qttV1=RandomizadorNumeros(1,MAXVECTOR1);
	qttV2=RandomizadorNumeros(1,MAXVECTOR2);

	omplirVector(v1,qttV1);
	omplirVector(v2,qttV2);
	
	pintavector(v1,qttV1);
	pintavector(v2,qttV2);
	if (totsDintre(v1,qttV1,v2,qttV2))
	{
		printf("Ta");
	}
	else
	{
		printf("No ta");
	}
	


	acabament();
	return 0;
}
