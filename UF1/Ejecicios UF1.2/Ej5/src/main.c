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
	int numero, total;
	numero=demanarNumero();
	total=calculaSumaNumerosAnterior(numero);
	pinta(numero, total);

	acabament();
	return 0;
}
