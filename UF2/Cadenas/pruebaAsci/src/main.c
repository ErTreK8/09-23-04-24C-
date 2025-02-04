#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));

	
	getch();
	// A== 65 Z==90
	/*
	for (int i = 'A'; i <='Z'; i++)
	{
		printf("[%d]:%c\t\n",i,i);
	}
	for (int i = 'a'; i <='z'; i++)
	{
		printf("[%d]:%c\t\n",i,i);
	}
	*/

	char cadena[20]='Hola DAM1';

	// strelen es el 20 de la cadena
	separa(cadena,strlen(cadena));




	acabament();
	return 0;
}
