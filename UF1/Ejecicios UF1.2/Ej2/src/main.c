#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"
// lops DEFINES VAN en la libreria pero en la que es .h
int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	int numero;

	numero=demanarNumero();
	demanarNotas(numero);


	acabament();
	return 0;
}
