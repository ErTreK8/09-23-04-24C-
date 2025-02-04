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
	const char fitxer[]="./fitxers/empleats.txt";
	const char fitxer2[]="./fitxers/empleats2.txt";
	const char fitxer3[]="./fitxers/prueba.txt";



	
	FILE *f;
	
	f=obrirFItxer(fitxer3,"w");
	exercici(f);

 	printf("\n%ld",ftell(f));
	
	
	
	
	
	
	
	//FILE *f[255];
	
	// f[1]=obrirFItxer(fitxer,"w");
	// f[2]=obrirFItxer(fitxer2,"w");
	// if (f!=NULL)
	// {
	// 	omplir(f[1]);
	// 	fputs("Hola",f[2]);
	// 	cls();
	// 	printf("\n%ld",ftell(f[1]));
	// 	printf("\n%ld",ftell(f[2]));

	// 	fclose(f[1]);
	// 	fclose(f[2]);
		
		// borra el fitxero
		//remove(fitxer);

	//}
	

// // Crear el fitxero en modo Write (borra el anterior si habia)
	// f=fopen("./fitxers/empleats.txt","a");
	// if (f==NULL) printf("No s'ha pogut crear el fitxer");
	// else 
	// {
	// 	printf("Se ha creado el fitxero");
	// 	fseek(f,0,SEEK_END);
	// 	// colocar cosas en el fitxero
	// 	fputc("A",f);
	// 	printf("\n%d",fputc("b",f));
	// 	printf("\n%d",fputc("C",f));
	// 	printf("\nFTELL: %ld",ftell(f));
	// 	printf("\n%d",fclose(f));
	// 	printf("\n%d",fputc("b",f));
	// 	f=NULL;		
	// 	// para la conexion

	// }


	acabament();
	return 0;
}
