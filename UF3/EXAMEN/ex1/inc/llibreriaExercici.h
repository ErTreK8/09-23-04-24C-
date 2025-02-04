#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'

#define UBICACIOFITXERORIGEN "./fitxers/malalties.txt"
#define UBICACIOFITXRESUM "./fitxers/malaltiesSimptoma.txt"

typedef struct {
    char malaltia[20];
    int qttSimpto;
}MALALTIA;

typedef struct {
    char malaltia[20];
    char simptoma[30];
}SIMPTOMA;



void llegirFitxer(char []);
void saltaLinea(FILE *);
MALALTIA agafaMalaltia(FILE *);
void agafaSimptoma(FILE *,char []);
void escriu(SIMPTOMA );
void escriuBarres();


#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
