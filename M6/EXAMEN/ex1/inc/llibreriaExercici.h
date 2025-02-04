#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'

#define UBICACIOAUXILIAR "./fitxers/auxiliar.dat"
#define UBICACIOCONTRASENYA "./fitxers/contrasenyes.dat"

typedef struct
{
    char login[30];
    char contrasenya[30];
    bool bloquejat;
}CONTRASENYA;



int calculaTotal(char [], int );
void llegirFitxer();
void modificaFitxer();
bool existeixContrasenyaUser(char [], char []);
bool estaBloquejat(char []);
int buscaUsers(char []);
bool existeixLogin(char []);
void insertarUser(CONTRASENYA ,char []);



#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
