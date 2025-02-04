#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>
#define MAXPUNTS 100
#define MINX 1
#define MAXX 80
#define MINY 1
#define MAXY 20
void demanaGPS(int *,int *);
void pinta(int ,int ,char ,int );
void generaPunt(int *,int *,int ,int );
bool controlaPunts(int ,int ,int ,int );
float calculaDistancia(int , int , int , int );
#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
