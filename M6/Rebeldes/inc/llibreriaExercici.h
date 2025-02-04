#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define MAXNOM 50


#define UBICACIOPILOT "./fitxers/pilots.dat"
#define MISIO "./fitxers/missio"
#define DAT ".dat"

#define UBICACIOAUXILIAR "./fitxers/auxiliar.dat"

enum OPCIONSMENU
{
    AFEGIR=1,
    MISSIO,
    RETORN,
    MOSTRAPILOT,
    MOSTRAMISSIO,
    SORTIR
};

typedef struct
{
    char nom[MAXNOM];
    bool jedi;
    int habilitat;
    bool estaEnMissio;
}PILOT;


int preguntaOpcio();
void inserirPilot();
bool existeixPilot(char []);
void inserirUnPilot(PILOT , char []);
void mostrarPilot();
int calculaTotal(char [], int );
void inserirMissio();
void rellenaVariables(int *,int *,int *);
void comprobacionsMissio(int ,int ,int ,int );
void creaFitxerMissio(char [],int ,int ,int );
bool buscaJedi(int);
int buscaPilots(int);
int buscaNumeroMissio();
void reseteaCadena(char [],int );
void mostrarMissions();
void retornaMissio();
int iniciRetorna(int *,int *, bool *);
bool existeixMissio(int );
void tornaMisio(int ,int );
bool existeixPilot2(char []);
void mostraPilotsMissio();
void mostrarPilot2(char []);


#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
