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
	int x=40,y=10,numero=1, color=1, comprobacion=0;
	char letra;
	bool bucle=false;
	getchar();
	quadrat();
	while (bucle!=true)
	{
		preguntaMover(&letra,&numero);
		modificarXY(letra,numero,&x,&y,&color,&comprobacion);
		setBackgroundColor(BLACK);
		gotoxy(40,10);
		printf("0");
		salirBucle(&bucle,x,y,letra,comprobacion);
	}
	fuera();
	acabament();
	return 0;
}
