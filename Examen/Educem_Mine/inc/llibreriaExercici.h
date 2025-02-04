#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIN_FILA 0
#define MAX_FILA 2
#define MIN_COLUMNA 0
#define MAX_COLUMNA 9
#define BUCLE_U 15
#define BUCLE_M 9
#define MAX_NUM_CASELLA 29
#define MIN_NUM_CASELLA 0

void aconseguiMines(int*, int*, int*, int*, int*);
int calcularCasellaMina();
void pintaTaulell(int, int, int, int, int);
char UoM();
void salirBucleM(int*, int, int*, int, int , int, int, int);
void salirBucleU(int*, int, int*, int, int , int, int, int);
int calcularCasella(int,int);
void printaFinal2(int, int, int, int, int, int);
void printaFinal3(int, int, int, int, int, int);
#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
