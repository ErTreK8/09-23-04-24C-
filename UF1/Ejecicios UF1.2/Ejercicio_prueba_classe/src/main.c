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

	/*Demana dos nombres i imprimeix quin es el mes gran*/
	int num1, num2, maxim;

	num1=demanaNum();
	num2=demanaNum();
	maxim=calculNumMax(num1,num2);
	mostrarResultat(num1,num2,maxim);
	

	
	acabament();
	return 0;
}
