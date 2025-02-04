#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void pintaCapsalera()
{
    setColor(BLUE);
    rectangle(40, 5, 80, 10);
    rectangle(40, 12, 80, 20);
    rectangle(40, 21, 59, 25);
    rectangle(61, 21, 80, 25);
    rectangle(34, 12, 38, 20);
    rectangle(82, 12, 86, 20);
    setColor(GREEN);
    rectanglePle(50, 7, 55, 8);
    rectanglePle(65, 7, 70, 8);
    setColor(RED);
    rectanglePle(57, 9, 63, 9);
    setColor(WHITE);
    gotoxy(50, 16);
    printf("CAMPS AMB ANDROIDES");
    getch();
    cls();
}
void rectangle(int xo, int yo, int xfinal, int yfinal)
{
    for (int fila = yo; fila <= yfinal; fila++)
    {
        for (int col = xo; col <= xfinal; col++)
        {
            if (fila == yo || fila == yfinal || col == xo || col == xfinal)
            {
                gotoxy(col, fila);
                printf("%c", 149);
                Sleep(3);
            }
        }
    }
}
void rectanglePle(int xo, int yo, int xfinal, int yfinal)
{
    for (int fila = yo; fila <= yfinal; fila++)
    {
        for (int col = xo; col <= xfinal; col++)
        {
            gotoxy(col, fila);
            printf("%c", 149);
            Sleep(3);
        }
    }
}

int preguntaOpcio()
{
    char opcionsMenu[SORTIR][40] = {"Insertar tipo Androide","Insertar Androide","Mostrar Androides","Insertar Campo","Mostrar Camps","Jornada de Trabajo","Salir"};

    int op;
    printf("MENU:\n");
    for (int i = 0; i < SORTIR; i++)
    {
        printf("%d.- %s\n", i + 1, opcionsMenu[i]);
    }

    printf("\nIntrodueix quina opcio vols fer? [%d-%d]: ", 1, SORTIR);
    op = demanarNumeroMinMax(AFEGIRANDROIDE, SORTIR);
    return op;
}

void insertTipo(TIPOANDROIDE tipo[], int *qttTipo)
{
    char cadena[(MIDA*2)];
    char auxCad[MIDA];
    bool igual=false;
    int pos=-1;
    int error=0;
    printaTipus(tipo,*qttTipo);
    do
    {
        if (error==1) printf("No hi ha nom o no s'ha ficat els :");
        else if (error==2) printf("El nom del tipus ja existeix");
        pos=-1;
        error=0;
        igual=false;
        printf("\nIntrodueix un tipus de androide (nom:descripcio): ");
        entrarCadena(cadena,sizeof(cadena));
        pos=busca2Punts(cadena,strlen(cadena));
        if (pos>0)
        {
            if (*qttTipo!=-1)
            {
                igual=esIgual(cadena,sizeof(cadena),pos,tipo,*qttTipo);
            } 
        } 
        else error=1;
        if (igual==true) error=2;
        
    } while (error!=0);
    
    
    for (int i = 0; i < pos; i++)
    {
        auxCad[i]=cadena[i];
    }
    auxCad[pos]='\0';
    strcpy(tipo[*qttTipo].nom,auxCad);
    auxCad[0]='\0';
    int j=0;
    int mida=strlen(cadena);
    for (int i = (pos+1); i < mida; i++)
    {
        auxCad[j]=cadena[i];
        j++;
    }
    auxCad[j]='\0';
    strcpy(tipo[*qttTipo].descripcio,auxCad);
    (*qttTipo)++;
    printaTipus(tipo,*qttTipo);
}

bool esIgual(char cadena[],int mida, int pos,TIPOANDROIDE tipo[],int qttTipo)
{

    bool esIgual=false;
    int i=0;
    char auxCad[mida];
    for (i = 0; i < pos; i++)
    {
        auxCad[i]=cadena[i];
    }
    auxCad[i]='\0';

    i=0;
    while (esIgual==false && i<qttTipo)
    {
        if (strcmpi(auxCad,tipo[i].nom)==0)
        {
            esIgual=true;
        }
        else
        {
            i++;
        }
 
    }
    return esIgual;
}

int busca2Punts(char cadena[],int mida)
{
    int pos=0;
    int posReal=-1;
    bool trobat=false;
    while (pos<mida && trobat==false)
    {
        if (cadena[pos]==':')
        {
            trobat=true;
        }
        else
        {
            pos++;
        }
    }
    if (trobat==true)
    {
        posReal=pos;
    }
    
    return posReal;
}


void printaTipus(TIPOANDROIDE tipo[], int qttTipo)
{
    if (qttTipo==0)
    {
        setColor(RED);
        printf("No hi ha cap Tipus d'androide inserit en el Sistema");
        setColor(WHITE);
    }
    else
    {
        printf("\nTipus d'Androides");
        for (int i = 0; i < qttTipo; i++)
        {
            printf("\n [%d]- %-5s :%s",i+1,tipo[i].nom, tipo[i].descripcio);
        }
        printf("\n\n");
    }
}


void insertDroid(ANDROIDE droid[], int *qttDroid,TIPOANDROIDE tipo[],int qttTipo)
{
    char cadena[MIDA];
    int error=0;
    bool exist;
    do
    {
        if (error==1) printf("El tipus Introduit no es correcte. Insereix un tipus valid: ");
        else  printf("\nIntrodueix quin tipus de androide es: ");
        exist=true;
        error=0;
        entrarCadena(cadena,sizeof(cadena));
        exist=existeixTipus(cadena,tipo,qttTipo);
        if (exist==false) error=1;
    } while (error!=0);
    
    strcpy(droid[*qttDroid].tipo,cadena);
    droid[(*qttDroid)].numeroSerie=100+(*qttDroid);
    droid[(*qttDroid)].velocidad=RandomizadorNumeros(10,100);
    (*qttDroid)++;
    printf("\n-----ANDROIDE INSERIT AL SISTEMA-----");
}

bool existeixTipus(char cadena[], TIPOANDROIDE tipo[],int qttTipo)
{

    bool esIgual=false;
    int i=0;

    i=0;
    while (esIgual==false && i<qttTipo)
    {
        if (strcmpi(cadena,tipo[i].nom)==0)
        {
            esIgual=true;
        }
        else
        {
            i++;
        }
    }
    return esIgual;
}

void printDroid(ANDROIDE droid[],int qttDroid)
{
    if (qttDroid==0)
    {
        setColor(RED);
        printf("NO HI HA CAP ANDROIDE INSERIT\n");
        setColor(WHITE);
    }
    else
    {
        printf("\n");
        for (int i = 0; i < qttDroid; i++)
        {
            setColor(GREEN);
            printf("nº%d:   Serie: %03d   Tipus: %s   Velocitat: %d\n",i+1,droid[i].numeroSerie,droid[i].tipo, droid[i].velocidad);
            setColor(WHITE);
        }
        Sleep(2000);
    }
}

void insertCamp(CAMP campo[],int *qttCampo)
{
    char cadena[MIDA];
    int error=0;
    bool sortir=false, exist=false;
    do
    {
        printaNomCamps(campo,*qttCampo);
        printf("\n");
        do
        {
            if (error==1) 
            {
                setColor(RED);
                printf("Has introduit un camp ja Existent\n");
                setColor(WHITE);
            }
            else if (error==2)  
            {
                setColor(RED);
                printf("No Has introducido un nombre al Campo\n");
                setColor(WHITE);
            }
            else if (error==3) 
            {
                setColor(RED);
                printf("No Puedes Crear un campo llamado f o F \n");
                setColor(WHITE);
            }
            error=0;
            printf("Introduiex el nom del camp ('s' per sortir (i no introduir cap camp)): ");
            entrarCadena(cadena,sizeof(cadena));
            sortir=haPosatS(cadena,strlen(cadena));
            exist=existeixCamp(cadena,campo,(*qttCampo));
            if (sortir==true);
            else if (cadena[0]=='\0' || cadena[0]==' ') error=2;
            else if (exist==true) error=1;
            else if ((cadena[0]!='f' || cadena[0]!='F') && cadena[1]=='\0') error=3;
        } while (error!=0);
        if (sortir!=true)
        {
            strcpy(campo[*qttCampo].name,cadena);
            campo[*qttCampo].numProd=0;
            campo[*qttCampo].activeDroid=0;
            (*qttCampo)++;
            printf("Campo Introducido Correctamente");
            Sleep(1000);
            printf("\n\n");
        }
    } while (sortir==false);
}


bool existeixCamp(char cadena[], CAMP camp[],int qttCampo)
{

    bool esIgual=false;
    int i=0;

    i=0;
    while (esIgual==false && i<qttCampo)
    {
        if (strcmpi(cadena,camp[i].name)==0)
        {
            esIgual=true;
        }
        else
        {
            i++;
        }
    }
    return esIgual;
}

bool haPosatS(char cadena[],int mida)
{
    bool hayS=false;
    if ((cadena[0]=='s' || cadena[0]=='S') && mida==1)
    {
        hayS=true;
    }
    return hayS;
}



void printaNomCamps(CAMP campo[], int qttCampo)
{
    if (qttCampo>0)
    {
        setColor(GREEN);
        printf("\nCamp de Cultiu Existents: \n");
        for (int i = 0; i < qttCampo; i++)
        {
            setColor(LIGHTBLUE);
            printf("%s \n",campo[i].name);
            setColor(WHITE);
        }
    }    
    else
    {
        setColor(RED);
        printf("No existeixen Camps\n");
        setColor(WHITE);
    }
}


void mostrarCamps(CAMP campo[],int qttCampo)
{
    setColor(GREEN);
    printf("CAMPS DE CULTIU: \n");
    for (int i = 0; i < qttCampo; i++)
    {
        setColor(BLUE);
        printf("CAMP: %s (%d)\n",campo[i].name,campo[i].numProd);
        printDroid(campo[i].workingDroid,campo[i].activeDroid);
        printf("\n");
    }
}

void joranada(CAMP campo[],int *qttCampo,ANDROIDE droid[],int *qttDroid)
{
    // PAS 1
   
    printf("Jornada de Treball:\n");
    printf("Pas 1: Inserir Productes per Recolectar Als Camps\n");
    mostrarCamps(campo,*qttCampo);
    char cadena[MIDA];
    bool existe=true;
    bool sortir=false;
    int productes;
    int pos;
    do
    {
        do
         {   
            if (existe==false) printf("\nEscribe un campo que exista Porfavor");
            printf("\nIntrodueix el nom del camp: (introdueix f per sortir): ");
            entrarCadena(cadena,sizeof(cadena));
            existe=existeixCamp(cadena,campo,*qttCampo);
            if ((cadena[0]!='f' || cadena[0]!='F') && cadena[1]=='\0') sortir=true;
        } while (existe!=true && sortir==false);
        
        if (sortir==false)
        {
            printf("Introdueix la quantitat de productes a recolectar: ");
            productes=demanaNumUnLimitInt(1);
            pos=posCampo(cadena,campo,*qttCampo);
            campo[pos].numProd+=productes;
            setColor(GREEN);
            printf("\n-----QUANTITAT DESADA CORRECTAMENT-----\n");
            setColor(WHITE);
        }
    } while (sortir!=true);
   
    // PAS 2
   
    cls();
    printf("Jornada de Treball:\n");
    printf("Pas 2: Llistat de Productes a Recolectar\n");
    mostrarCamps(campo,*qttCampo);
    
    // PAS 3 
   
    
    int prodTotal;
    prodTotal=calculaProdTotal(campo,*qttCampo);
    if(prodTotal>0)
    {
        cls();
        printf("Jornada de Treball:\n");
        printf("Pas 3: Assignacio Andorides Als Diferents Camps\n");
        
        int minimDroid;
        int posCamp;

        int vectorPosDroid[MAXANDROIDE];
        int qttPosDroid=0;
        do
        {
            minimDroid=buscaMinim(campo,*qttCampo);
            comptaMinimDroid(campo,*qttCampo,minimDroid,vectorPosDroid,&qttPosDroid);
            if (qttPosDroid>1) 
            {
                posCamp=buscaMesProductes(campo,vectorPosDroid,qttPosDroid);
                insertDroidInCamp(posCamp,campo,droid, &(*qttDroid));
            }
            else
            {
                insertDroidInCamp(vectorPosDroid[0],campo,droid, &(*qttDroid));
            }    
        } while (*qttDroid!=0);
    


        mostrarCamps(campo,*qttCampo);
        Sleep(2000);
        
        // PAS 4

        cls();
        printf("Jornada de Treball:\n");
        printf("Pas 4: Proceso De Recolectar y Recuento al Finalizar el Dia\n");

        int prodRecollit=0;
        for (int i = 0; i < *qttCampo; i++)
        {
            prodRecollit=0;
            if (campo[i].activeDroid>0)
            {
                for (int j = 0; j < campo[i].activeDroid; j++)
                {
                    prodRecollit=prodRecollit+(campo[i].workingDroid[j].velocidad*5);
                }
                campo[i].numProd=campo[i].numProd-prodRecollit;
                if (campo[i].numProd<0)
                {
                    campo[i].numProd=0;
                }
            }
        }
        

        mostrarCamps(campo,*qttCampo);
        Sleep(3000);
        
        // PAS 5
        cls();
        printf("Jornada de Treball:\n");
        printf("Pas 5: Proceso Devolver los Androides a Casa\n");

        for (int i = 0; i < *qttCampo; i++)
        {
            if (campo[i].activeDroid>0)
            {
                for (int j = 0; j < campo[i].activeDroid; j++)
                {
                    droid[*qttDroid]=campo[i].workingDroid[j];
                    (*qttDroid)++;
                }
                campo[i].activeDroid=0;
            }
        }
        
        mostrarCamps(campo,*qttCampo);
        Sleep(3000);
    }
    else
    { 
        printf("\nNo hi ha producte que recollir\n");
        Sleep(2000);
    }
}

int posCampo(char cadena[],CAMP camp[],int qttCampo)
{
    int pos=-1;
    int i=0;

    i=0;
    while (pos==-1 && i<qttCampo)
    {
        if (strcmpi(cadena,camp[i].name)==0)
        {
            pos=i;
        }
        else
        {
            i++;
        }
    }
    return pos;
}

int calculaProdTotal(CAMP campo[],int qttCampo)
{
    int productos=0;
    for (int i = 0; i < qttCampo; i++)
    {
        productos+=campo[i].numProd;
    }
    return productos;   
}

int buscaMinim(CAMP campo[],int qttCampo)
{
    int minimo=21;
    for (int i = 0; i < qttCampo; i++)
    {
        if (campo[i].activeDroid<minimo)
        {
            minimo=campo[i].activeDroid;
        }
    }
    return minimo;
}

void comptaMinimDroid(CAMP campo[],int qttCampo, int minim,int vectorPosDroid[],int *qttPosDroid)
{
    for (int i = 0; i < qttCampo; i++)
    {
        if ((campo[i].activeDroid)==minim)
        {
            vectorPosDroid[*qttPosDroid]=i;
            (*qttPosDroid)++;
        }
    }
}

int buscaMesProductes(CAMP campo[],int vectorPosDroid[],int qttPosDroid)
{
    int posCampo;
    int maxProd=0;
    for (int i = 0; i < qttPosDroid; i++)
    {
        if (campo[vectorPosDroid[i]].numProd>maxProd)
        {
            posCampo=vectorPosDroid[i];
        }
    }
    return posCampo;
}

void insertDroidInCamp(int posCamp,CAMP campo[],ANDROIDE droid[],int *qttDroid)
{
    int posDroid;
    posDroid=buscaMillorDroid(droid, *qttDroid);
    int vqtt=campo[posCamp].activeDroid;
    campo[posCamp].workingDroid[vqtt]=droid[posDroid];
    campo[posCamp].activeDroid++;
    mouAndroide(droid,&(*qttDroid),posDroid);
}

int buscaMillorDroid(ANDROIDE droid[],int qttDroid)
{
    int posDroid;
    int maxVelo=0;
    for (int i = 0; i < qttDroid; i++)
    {
        if (maxVelo<droid[i].velocidad)
        {
            maxVelo=droid[i].velocidad;
            posDroid=i;
        }
    }
    return posDroid;
}

void mouAndroide(ANDROIDE droid[],int *qttDroid, int posDroid)
{
    for (int i = posDroid; i < *qttDroid-1; i++)
    {
        droid[i]=droid[i+1];
    }
    (*qttDroid)--;
}



