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

//	int v[]={1,67,10,33,16,4,12,0};
	int v[]={1,2,3,4,5,6,7,8};

    printf(" %d  %d ",sizeof(v),sizeof(int));
    printf("\nSense Ordenar:\n");
    pintavector(v,sizeof(v)/sizeof(int));
    printf("\nOrdenats:\n");
    ordenar2(v,sizeof(v)/sizeof(int));
    pintavector(v,sizeof(v)/sizeof(int));
	acabament();
	return 0;
}
