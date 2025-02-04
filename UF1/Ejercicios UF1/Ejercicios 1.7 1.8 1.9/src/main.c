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
/*
	char letra, letraAnt1, letraAnt2, letraAnt3, letraAnt4, letraAnt5;
	int vocales=0;
	
	while (vocales != 5 || letra != '.')
	{

		while(getchar()!='\n');
		
		printf("\nDime una letra(. para acabar):");
		scanf("%c", &letra);
		if	(letra=='a' && letraAnt1 != 'a')
		{
			letraAnt1=letra;
			vocales++;
		}
		else if	(letra=='e' && letraAnt2 != 'e')
		{
			letraAnt2=letra;
			vocales++;
		}
		else if	(letra=='i' && letraAnt3 != 'i')
		{
			letraAnt3=letra;
			vocales++;
		}
		else if	(letra=='o' && letraAnt4 != 'o')
		{
			letraAnt4=letra;
			vocales++;
		}
		else if	(letra=='u' && letraAnt5 != 'u')
		{
			letraAnt5=letra;
			vocales++;
		}
	}
	if (vocales==5)
	{
		printf("Felicidades tienes las 5 vocales");
	}
	else
		printf("Felicidades no tienes las 5 vocales");
*/
//Ejercicio 1:
    /*
    int num=-1,numAnt=0,cont=0,division;
    while (num!=0)
    {
        printf("Introduce un numero: ");
        scanf("%d",&num);
        cont++;
        
        if (numAnt!=0 && num==0 && cont==2)
        {
            printf("Solo se ha introducido un número valido\n");
        }
        else if (num==0 && numAnt==0 && cont==1)
        {
            printf("No se ha introducido ningún número válido\n");
        }
        if (num!=0){
        division=numAnt%num;
        if (division==0 && cont>=2 && num!=0)
        {
            printf("si, ya que %d es divisible entre %d\n",numAnt,num);
        }
        else if (division!=0&&cont>=2 && num!=0)
        {
            printf("no, ya que %d no es divisible entre %d\n",numAnt,num);
        }
        numAnt=num;
        }
    }
    */
    //Ejercicio 2:
    /*
    char car='B',carAnt='B';
    int vocals1=0,vocals2=0;
    

    while(vocals1==0 || vocals2==0){
        carAnt=car;
        car=65+rand()%(90-65+1);
        if (carAnt=='A'||carAnt=='E'||carAnt=='I'||carAnt=='O'||carAnt=='U')
        {
            vocals2=1;
        }
        else{
            vocals2=0;
        }
        
        if (car=='A'||car=='E'||car=='I'||car=='O'||car=='U')
        {
            vocals1=1;
        }
        else{
            vocals1=0;
        }
        fflush(stdin);
        printf("%c",car);
    }
    */
   //Ejercicio 3:
    /*
    char car,carAnt;
    int vocals=0;

    while (vocals<10)
    {
        car=65+rand()%(90-65+1);
        if (car!='A'&& car!='E' && car!='I' && car!='O' && car!='U')
        {
            vocals++;
        }
        else{
            vocals=0;
        }
        printf("%c",car);
    }
    */	
   //Ejercicio 4
   /*
   int fivo=0, fivoAnt=0, fivoAnt2=1;
   for (int i = 0; i <= 7; i++)
    {        
        printf("[%d] %d \n", i, fivo);
        fivo=fivoAnt2+fivoAnt;
        fivoAnt2=fivoAnt;
        fivoAnt=fivo;
        
    }
    */


//Ejercicio 5
/*
    char car,carAnt;
    int la=0;
    while (car!='.')
    {
        printf("Introduce un caracter ('.' per sortir): ");
        scanf("%c",&car);
        while(getchar()!='\n');
        if ((car=='a'||car=='A')&&(carAnt=='l'||carAnt=='L'))
        {
            la++;
        }
        carAnt=car;
    }
    printf("Han aparecido %d la",la);
*/

//Ejercicio 1 1.8
/*
    int num=0,numAnt=0,numAnt2=0, cont=1;

    while (cont<3)
    {
        printf("Introduce un numero: ");
        scanf("%d",&num);
        if (num>numAnt && numAnt>numAnt2 && cont<3)
        {
            cont++;
        }
        else
        {
            cont=1;
        }
        numAnt2=numAnt;
        numAnt=num;
    }
    printf("\nHas introducido 3 numeros crecientes");
*/


//Ejercicio 1 (1.9)
/*
        char car, carAnt = ' ';
        int paraules = 0;

        while (car != '.') {
            //Pregunta la letra de la frase para scanearla

            printf("Introduce una Frase letra por letra ('.' para salir): ");
            scanf("%c", &car);

            //Limpia el teclado
            while (getchar() != '\n');

    //EN teoria tiene q funcionar pero si carant es un espacio y la letra q han puesto ahora no lo es y es una letra suma 1 a paraules
            if (carAnt == ' ' && car != ' ') {
                paraules++;
            }
            carAnt = car; 
        }

        printf("Has Puesto %d Palabras", paraules);
*/


//Ejercici 2 (1.9)
/*
    int ant=0, numero=1, cont=0, ant2;
        while (numero!=0)
        {
            printf("Introduce un Dime un numero: ");
            scanf("%d",&numero);
            if (numero==0)
            {
                printf("S'ha acabat la introduccio de nombres\n");
            }
            else if (numero>ant && ant>ant2 && cont<=0)
            {
                cont=0;
                cont++;
            }
            
            else if (numero<ant && ant<ant2 && cont<0)
            {
                cont--;
            }
            else if (numero<ant && ant<ant2 && cont>=0)
            {
                cont=0;
                cont--;
            }
            else if (numero>ant && ant>ant2 && cont>0)
            {
                cont++;
            }
            
            else{
                cont=0;
            }
            ant2=ant;
            ant=numero;
        }
        
        if (cont>0)
        {
            printf("Creix");
        }
        else if (cont<0)
        {
            printf("No creix");
        }
        else
            printf("Ni creix ni Decreix");
*/


	acabament();
	return 0;
}
