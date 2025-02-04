#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define UBICACIOFITXERORIGEN "./fitxers/preins.csv"
#define UBICACIOFITXERORIGENCOPIA "./fitxers/preins1.csv"
#define UBICACIOFITXRESUM "./fitxers/resum.txt"

typedef struct {
    char IDpreins[11];
    char inicials[7];
    char escola[8];
    int adscrita;
    int puntuacio;
}ALUMNE;

typedef struct {
    char escola[8];
    int qttSi;
    int qttNo;
}ESCOLA;

void llegirFitxer(char []);
void copiaArixu(char [],char []);
void saltaLinea(FILE *);
ALUMNE agafaAlumne2(FILE *);
bool existeixEscola(char []);
void cojeEscuelaResum(FILE *,char []);
void escriu(ESCOLA);


#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
