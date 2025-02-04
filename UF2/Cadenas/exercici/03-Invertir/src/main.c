#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));

	char frase[] = "--Hola DAM--",fraseInvertida[strlen(frase)];

	printf("la cadena és:\n %s",frase);


	invertirCadena(frase,fraseInvertida,strlen(frase));
	
	printf("\nla cadena invertida és: \n");
	printf("%s",frase);
	//pintaFrase(fraseInvertida,strlen(frase));


	acabament();
	return 0;
}
