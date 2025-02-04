#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	/*Fer Calculadora
	Demanar 2 nombres(decimals)
	+ - * /
	mostrar resultat*/

	float num1, num2, resultat;
	char simbol;

    num1=demanaNum();
	num2=demanaNum();
	simbol=demanaSimbol();
	switch(simbol)
	{
		case '+':resultat=suma(num1,num2);break;
		case '-':resultat=resta(num1,num2);break;
		case '*':resultat=multiplicacion(num1,num2);break;
		case '/':resultat=division(num1,num2);break;
		default:resultat=0;break;
	}

	mostrarResultat(num1,num2,simbol,resultat);
	acabament();
	return 0;
}
