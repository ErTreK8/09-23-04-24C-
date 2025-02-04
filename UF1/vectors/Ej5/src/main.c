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

	int v[MAXVECTOR]={};
	int v2[MAXVECTOR]={0};
	int i=0, qtt=0;
	while (i<MAXVECTOR && v[i-1]!=-1)
	{
		v[i]=demanarNumeroMinMax(-1,99);
		v2[v[i]]++;;
		i++;
		qtt++;
	}
	pintaVector2(v2, MAXVECTOR);

	acabament();
	return 0;
}