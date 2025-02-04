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
	int numero;
	char caracter;
	printf("Introduce un caracter: ");
	caracter=demanaCaracter();
	printf("\nIntroduce un numero: ");
	numero=demanaNumero();
	printa(caracter, numero);
	acabament();
	return 0;
}
