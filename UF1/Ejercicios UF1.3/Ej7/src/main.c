#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"



int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	int gpsx,gpsy,xMin,yMin,x,y;
	float dist, distMinima;

	demanaGPS(&gpsx,&gpsy);
	cls();
	pinta(gpsx,gpsy,'G',GREEN);
	
	for (int punt=1;punt<=MAXPUNTS;punt++)
	{
		generaPunt(&x,&y,gpsx,gpsy);
		pinta(x,y,'P',BLUE);
		dist=calculaDistancia(x,y,gpsx,gpsy);
		if (punt==1 || punt>1 && dist<distMinima)
		{
			distMinima=dist;
			xMin=x;
			yMin=y;
		}
	}
	pinta(xMin,yMin,'C',RED);

	acabament();
	return 0;
}
