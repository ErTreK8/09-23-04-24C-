#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"
/*1.	(NotaNumericaaLLetres) Fer un programa que demani una nota compresa entre 1 i 10 i
 posteriorment transformi la nota en la seva qualificaci� en lletres. */


int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	int v[MAXVECTOR];
	int pos;
	int num;
	for (int qtt=0;qtt<MAXVECTOR;qtt++)
	{
		printf("Introdueix el numero: ");
		num=demanaNumInt();
		pos=calculaPosicio(v,qtt,num);
		moure(v,qtt,pos);
		v[pos]=num;
		pintavector(v,qtt+1);
		printf("\n------------------\n");
	}

	

	acabament();
	return 0;
}
