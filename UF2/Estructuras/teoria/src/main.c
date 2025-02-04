#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	//1252 coje codigos distintos no como el UTF_8 i akgi asu¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	
	ARTICLE art={"pera","fruita",1.90};
	ARTICLE art2;


	pintaArticle(art);
	//Omplir el nou Article
	demanarArticle(&art2);
	while (getchar()!='\n');
	pintaArticle(art2);

	//Opcion Facil
	art2=demanarArticle2();

	// copiar el contenido de art a art2

	art2=art;

	acabament();
	return 0;
}
