#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


#define UBICACIOFITXERORIGEN "./fitxers/origen.txt"
#define UBICACIOFITXRESUM "./fitxers/resum.txt"
#define UBICACIOFITXRESUMCOPIA "./fitxers/resumCopia.txt"
#define UBICACIOFITXRESUMBONIC "./fitxers/resumBonic.txt"
typedef struct
{
    char esport[50];
    char nacionalitat[50];
}ESPORTNACIONALITAT;

typedef struct
{
    char esport[50];
    char nacionalitat[50];
    int cont;
}ESPORTNACIONALITATRESUM;





