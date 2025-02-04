#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MAXVECTORCARTES 49
#define MAXVECTORJUGADORS 3
#define MAXVECTORCARTESGUANYADES 48  
void rellenarBaraja(int[], int*);
void repartirCartasJugadrors(int[], int, int *, int [], int *);
int sacarCartaAletoriaBaraja(int[], int *);
void pedirCarta(int *, char *, int *);
void tirarCartaJugador(int *,char *,int *,int [], int);
int codificarCarta(char , int);
void decodificarCarta(int *, char *, int);
void pintaJugadorCartes(int [], int);
int puntsCarta(int);
int sacarNumeroCarta(int);
void pintaVectorHorizontal(int [], int);
void guanyadorRonda(bool *,int,char,int,int,char,int, char);
void cartasRondaEnGanadoras(bool,int *,int *,int [],int *,int [],int *,int *,int *,int ,int );
void quitarCartaJugadores(int [],int [],int *,int *,int *,int *);



#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */