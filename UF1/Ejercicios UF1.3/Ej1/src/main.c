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

	int num1, num2;
	printf("Escribe un numero entero: ");
	num1=demanarNumero();
	printf("Escribe un numero entero: ");
	num2=demanarNumero();
	intercanviVariables(&num1, &num2);
	printf("%d\n", num1);
	printf("%d\n", num2);

	acabament();
	return 0;
}
