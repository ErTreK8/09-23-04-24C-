#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define MAXVALORACIONS 5
#define MAXARMARI 5


enum OPCIONSMENU
{
    AFEGIRDISFRESSA=1,
    MOSTRADISFRESSA,
    AFEGIRVALORACIO,
    BAIXADISFRESSA,
    SORTIR
};

typedef struct
{
    bool vestit;
    bool gorra;
    bool sabates;
    int totalParts;
}PARTSDISFRESSA;

typedef struct
{
    char nom[MIDA];
    PARTSDISFRESSA parts;
    float preu;
    int valoracions[MAXVALORACIONS];
    int qttValo;
    float valoMitja;
    bool utilitzat;
}DISFRESSA;



int preguntaOpcio();
void vuidaArmari(DISFRESSA []);
void inserirDisfressa(DISFRESSA []);
void buscaPos(DISFRESSA [],int *,int *);
void buscaValoracions(int [],int *, DISFRESSA []);
int buscaMinimValo(DISFRESSA [],int [],int );
int buscaArmariAmbValo(DISFRESSA [],int );
int buscaMinimPreu(DISFRESSA []);
int buscaAramriAmbPreu(DISFRESSA [],int );
void inserirNomDisfressa(DISFRESSA [], int );
bool existeixDisfressa(char [], DISFRESSA []);
void introdueixParts(DISFRESSA [], int );
void mostraArmari(DISFRESSA []);
void posSioNo(bool);
float calculaValoMitja(int [], int );
void imprimeixValoracions(int [], int );
float demanaNumUnLimitIntFloat(int minim);
void insertaValoracions(DISFRESSA []);
void donarBaixaDisfressa(DISFRESSA []);
int buscaPosDisfressaNom(DISFRESSA [],char []);


#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
