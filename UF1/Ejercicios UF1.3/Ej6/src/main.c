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
	int x=40,y=10,tecla=0;
	bool bucle=false;
	getchar();
	quadrat();
	while (bucle!=true)
	{
		pintaColor(x,y);
		cojerTecla(&tecla);
		modificarXY(tecla,&x,&y);
		salirBucle(&bucle,x,y);
	}
	fuera();
	acabament();
	return 0;
}
