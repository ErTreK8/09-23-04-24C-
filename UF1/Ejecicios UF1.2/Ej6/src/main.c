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
	int numero, quantitat;
	printf("Introdueix un numero: ");
	numero=demanarNumero();
	quantitat=calculaQuantitatDigits(numero);
	pinta(numero, quantitat);

	acabament();
	return 0;
}
