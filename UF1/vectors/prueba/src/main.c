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
	int v[MAXVECTOR]={1,2,3,4,5,6,7,8,9};
	int vcopia[MAXVECTOR];
	int cont[3]={0};
	int parells=0, senars=0, zero=0, numeroMes=0,diesMes=0, numero=0, posicio=-1;
	int qtt=9;
	bool trobat=false;
	//omplirVectorUsuari(v,MAXVECTOR);
    //pintaVector(v,MAXVECTOR);

//	calculaParellsSenarsY0(v,MAXVECTOR,&parells,&senars,&zero);
//	printf("\nHi ha %d parells \nHi ha %d Senars \nHi ha %d zeros",parells,senars,zero);

	calculaParellsSenarsY02(v,MAXVECTOR,cont);
//	printf("\nHi ha %d parells \nHi ha %d Senars \nHi ha %d zeros",cont[1],cont[2],cont[0]);
/*
	printf("Dame un numero de mes: ");
	numeroMes=demanarNumeroMinMax(1,12);
	diesMes=calculaDiesMes(numeroMes);
	printf("\n\nEl mes %d te %d dies",numeroMes,diesMes);

	printf("%d",calculaMax(v,MAXVECTOR));
*/
/*
	copiarVector(v,MAXVECTOR,vcopia);
	pintaVector(v,MAXVECTOR);
	printf("\n\n");
	calculaSumes(v,MAXVECTOR);
	pintaVector(v,MAXVECTOR);
*/
/*
	int vParell[cont[1]];
	int vSenar[cont[2]];
	separarVector(v,MAXVECTOR,vParell,vSenar);
	pintaVector(vParell,cont[1]);
	printf("\n\n");
	pintaVector(vSenar,cont[2]);
*/

    // demana un numero a l'usuari i comprova si esta  --> true /false (cerca)
    // aquestes funcions s'han d'acabar en el moment de que trobem el valor

/*
	numero=demanarNumeroMinMax(0,10);
	trobat=cercaNumeroVector(numero,v,MAXVECTOR);
	if(trobat==true)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
*/

    //demana un numero i comprova en quina casella esta el primer cop que apareix (posicio)
    //aquestes funcions s'han d'acabar en el moment de que trobem el valor
    // posicio =-1 (si el numero no existeix
    // i la posicio valida si existeix)

/*
	numero=demanarNumeroMinMax(0,10);
	posicio=testPosition(numero,v,MAXVECTOR);
	if(posicio>-1)
	{
		printf("Esta en la posicio %d",posicio);
	}
	else
	{
		printf("no ta");
	}
*/
/*
	pintaVector(v,MAXVECTOR);
	printf("\n\n");
	invertirVector(v,MAXVECTOR);
	pintaVector(v,MAXVECTOR);
*/
	numero=demanarNumeroMinMax(0,10);
	pintaVector(v,qtt);
	printf("\n\n");
	eliminar(numero, v, &qtt, &posicio);
	pintaVector(v,qtt);

    // Inverteix un vector	
	acabament();
	return 0;
}
