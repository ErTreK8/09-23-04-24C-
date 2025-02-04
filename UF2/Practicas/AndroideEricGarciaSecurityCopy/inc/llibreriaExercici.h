#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define MAXANDROIDE 20

enum OPCIONSMENU
{
    AFEGIRANDROIDE=1,
    INSERTARANDROIDE,
    MOSTRARANDROIDE,
    INSERTARCAMP,
    MOSTRARCAMP,
    JORNADA,
    SORTIR
};

typedef struct
{
    char nom [MIDA];
    char descripcio[MIDA];
}TIPOANDROIDE;

typedef struct
{
    int numeroSerie;
    char tipo[MIDA];
    int velocidad;
}ANDROIDE;

typedef struct 
{
    char name[MIDA];
    int numProd;
    ANDROIDE workingDroid[MAXANDROIDE];
    int activeDroid;
}CAMP;

void pintaCapsalera();
void rectangle(int , int , int , int );
void rectanglePle(int , int , int , int );
int preguntaOpcio();
void insertTipo(TIPOANDROIDE [], int* );
bool esIgual(char [],int , int ,TIPOANDROIDE [],int );
int busca2Punts(char [],int );
void printaTipus(TIPOANDROIDE [], int );
void insertDroid(ANDROIDE [], int *,TIPOANDROIDE [],int );
bool existeixTipus(char [], TIPOANDROIDE [],int );
void insertCamp(CAMP [],int *);
bool existeixCamp(char [], CAMP [],int );
bool haPosatS(char [],int );
void printaNomCamps(CAMP [], int );
void printDroid(ANDROIDE [],int );
void mostrarCamps(CAMP [],int );
void joranada(CAMP [],int *,ANDROIDE [],int *);
int posCampo(char [],CAMP [],int );
int calculaProdTotal(CAMP [],int );
int buscaMinim(CAMP [],int );
void comptaMinimDroid(CAMP [],int , int ,int [],int *);
int buscaMesProductes(CAMP [],int [],int );
void insertDroidInCamp(int ,CAMP [],ANDROIDE [],int *);
int buscaMillorDroid(ANDROIDE [],int );
void mouAndroide(ANDROIDE [],int *, int );




#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */