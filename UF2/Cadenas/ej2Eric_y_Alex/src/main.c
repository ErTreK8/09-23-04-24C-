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
	
	printf("Grupo: Eric Garcia y Alex Batlles");
	getch();
	cls();
	
	int vector[20];
	int vector2[20];
	int qtt2=0;
	int comptador[5]={0};
	ompleVector(vector,20);
	printf("Vector Original:\n");
	pintavector2(vector,20);
	
	printf("\nVector cambiat:\n");
	cambiaVector(vector,20,vector2,&qtt2);
	pintavector2(vector2,qtt2);
	printf("\n\nRecompte de numeros de cada Valor");
	compteNum(vector2,qtt2,comptador,5);
	pintavector(comptador,5);

	acabament();
	return 0;
}
