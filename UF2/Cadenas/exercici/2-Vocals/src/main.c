#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "rlutil.h"
#include <windows.h>
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	srand(time(NULL));

	

	char frase[MAXCADENA] = "Demà aniré al cinema\n";
	char VocalsFrase[MAXCADENA] = "";
    char ConsonantsFrase[MAXCADENA] = "";

	
	
	// pintaCadena(frase,strlen(frase));
	printf("\n%s",frase);
	separarVocalsConsonants(frase,VocalsFrase,ConsonantsFrase,strlen(frase));

	printf("Vocals:%s",VocalsFrase);
	printf("\nConsonants:%s",ConsonantsFrase);

	acabament();
	return 0;
}
