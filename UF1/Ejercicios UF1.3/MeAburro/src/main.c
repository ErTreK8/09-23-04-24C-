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
	int x=40,y=10,tecla=0, xManzana=0, yManzana=0, digitos=0;
	int xant1=100, xant2=100, xant3=100, xant4=100, xant5=100, xant6=100, xant7=100, xant8=100, xant9=100, xant10=100, yant1=100, yant2=100, yant3=100, yant4=100, yant5=100, yant6=100, yant7=100, yant8=100, yant9=100, yant10=100;
	long score=1;
	bool bucle=false;
	(xManzana)=RandomizadorNumeros(2, 79);
    (yManzana)=RandomizadorNumeros(2, 19);
	while (bucle!=true)
	{
		cls();
		quadrat();
		pintaManzana(xManzana, yManzana);
		//pintaColor(x,y,score);
		prueba(score,&x, &y, &tecla, &xant1, &xant2, &xant3, &xant4, &xant5, &xant6, &xant7, &xant8, &xant9, &xant10, &yant1, &yant2, &yant3, &yant4, &yant5, &yant6, &yant7, &yant8, &yant9, &yant10);
		//cojerTecla(&tecla);
		//modificarXY(tecla,&x,&y);
		if (x==xManzana && y==yManzana)
		{
			score=score*10;
			manzana(&xManzana,&yManzana);
		}
		salirBucle(&bucle,x,y,score, xant1, xant2, xant3, xant4, xant5, xant6, xant7, xant8, xant9, xant10, yant1, yant2, yant3, yant4, yant5, yant6, yant7, yant8, yant9, yant10);
		setBackgroundColor(BLACK);
		setColor(WHITE);
	}
	digitos=calculaQuantitatDigits(score);
	cls();
	printf("La teva puntuacio final ha sigut de: %d", digitos);
	acabament();
	return 0;
}


