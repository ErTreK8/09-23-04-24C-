#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'

typedef struct {
    int numPregunta;
    char respostaAlumne;
}PREGUNTES;

enum OPCIONSMENU
{
    AFEGIR=1,
    MOSTRAR,
    SORTIR
};

int preguntaOpcio();
void creaArxiuCorrecte(int);
void responAlumne(int,char[]);
int demanarNumeroMinMax2(int,int);
void mostrar(char []);
void contadores(int[],char[],char[],int);
bool contestada(int , char []);
float calcula(int [] ,int );
void modificaRespota(PREGUNTES ,char []);
void insertarPreguntaNormal(PREGUNTES ,char []);
void insertarPrimeraPregunta(PREGUNTES ,char []);
#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
