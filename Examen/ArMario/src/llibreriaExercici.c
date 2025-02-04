#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int preguntaOpcio()
{
    char opcionsMenu[SORTIR][40] = {"Inserir Una Disfressa Nova","Mostrar Disfressa del Armari","Afegir Valoracio a Totes les Disfresses","Donar Baixa a una Disfressa","Sortir"};

    int op;
    printf("MENU:\n");
    for (int i = 0; i < SORTIR; i++)
    {
        printf("%d.- %s\n", i + 1, opcionsMenu[i]);
    }

    printf("\nIntrodueix quina opcio vols fer? [%d-%d]: ", 1, SORTIR);
    op = demanarNumeroMinMax(AFEGIRDISFRESSA, SORTIR);
    return op;
}

void vuidaArmari(DISFRESSA armari[])
{
    for (int i = 0; i < MAXARMARI; i++)
    {
        armari[i].utilitzat=false;
    }
}

void inserirDisfressa(DISFRESSA armari[])
{
    int pos=-1;
    int final=0;
    
    char nomAntigaDisfressa[MIDA];
    buscaPos(armari,&pos,&final);
    strcpy(nomAntigaDisfressa,armari[pos].nom);
    inserirNomDisfressa(armari,pos);
    introdueixParts(armari,pos);
    printf("Introdueix el Preu de la Disfressa: ");
    armari[pos].preu=demanaNumUnLimitIntFloat(0);
    armari[pos].qttValo=0;
    armari[pos].valoMitja=0;
    armari[pos].utilitzat=true;
    switch (final)
        {
        case 0:
            setColor(GREEN);
            printf("Disfressa Penjada a l'armari");
            setColor(WHITE);
            break;
        case 1:
            setColor(GREEN);
            printf("La disfresa %s s'ha eliminat del armari, ja que tenia pitjor valoracio", nomAntigaDisfressa);
            setColor(WHITE);
            break;
        case 2:
            setColor(GREEN);
            printf("La disfresa %s s'ha eliminat del armari, ja que tenia pitjor preu", nomAntigaDisfressa);
            setColor(WHITE);
            break;
        default:
            break;
        }    
}
float demanaNumUnLimitIntFloat(int minim)
{
    float n;
    do
    {
       scanf("%f",&n);
       if (n<minim)
       {
            printf("Introdueix un numero superior o igual a %d: ",minim);
       }
    } while (n<minim);
    return n;
}

void buscaPos(DISFRESSA armari[],int *pos,int *final)
{
    int posDisAmbValo[MAXARMARI];
    int qtt=0;
    int minimValo;
    int minimPreu;
    int i=0;

    while(i<MAXARMARI && (*pos)<0)
    {
        if (armari[i].utilitzat==false)
        {
            (*pos)=i;
        }
        else i++;
    }
    if ((*pos)<0)
    {
        buscaValoracions(posDisAmbValo,&qtt, armari);
        if (qtt==0)
        {
            minimPreu=buscaMinimPreu(armari);
            (*pos)=buscaAramriAmbPreu(armari,minimPreu);
            (*final)=2;
        }
        else
        {
            minimValo=buscaMinimValo(armari, posDisAmbValo,qtt);
            (*pos)=buscaArmariAmbValo(armari,minimValo);
            (*final)=1;
        }
    }
    else
    {
        (*final)=0;
    }
}

void buscaValoracions(int v[],int *qtt, DISFRESSA armari[])
{
    for (int i = 0; i < MAXARMARI; i++)
    {
        if (armari[i].utilitzat==true)
        {
            if (armari[i].qttValo>0)
            {
                v[(*qtt)]=i;
                (*qtt)++;
            }
        }
    }
}

int buscaMinimValo(DISFRESSA armari[],int v[],int qtt)
{
    int minim=6;
    for (int i = 0; i < qtt; i++)
    {
        if (armari[v[i]].valoMitja<minim)
        {
            minim=armari[v[i]].valoMitja;
        }
    }
    return minim;
}

int buscaArmariAmbValo(DISFRESSA armari[],int minimValo)
{
    int pos=-1;
    int i=0;
    while (i < MAXARMARI && pos==-1)
    {
        if (armari[i].utilitzat==true)
        {
            if (minimValo==armari[i].valoMitja)
            {
                pos=i;
            }
            else
            {
                i++;
            }
        }  
        else
        {
            i++;
        }      
    }
    return pos;
}


int buscaMinimPreu(DISFRESSA armari[])
{
    int minim=0;
    for (int i = 0; i < MAXARMARI; i++)
    {
        if (minim==0 && armari[i].utilitzat==true)
        {
            minim=armari[i].preu;
        }
        else if (armari[i].utilitzat==true)
        {
            if (minim>armari[i].preu)
            {
                minim=armari[i].preu;
            }
        }        
    }
    return minim;
}

int buscaAramriAmbPreu(DISFRESSA armari[],int preu)
{
    int pos=-1;
    int i=0;
    while (i < MAXARMARI && pos==-1) 
    {
        if (armari[i].utilitzat==true)
        {
            if (preu==armari[i].preu)
            {
                pos=i;
            }
            else
            {
                i++;
            }
        }        
        else
        {
            i++;
        }
    }
    return pos;
}



void inserirNomDisfressa(DISFRESSA armari[], int pos)
{
    char cadena[MIDA];
    int error=0;
    int exist=true;

    do
    {
        if (error==1) 
        {
            setColor(RED);
            printf("La disfressa Introduida ja Existeix.");
            setColor(WHITE);
            printf(" Introdueix una Disfressa que no tinguis: ");
        }
        else  printf("\nIntrodueix el nom de la Disfressa: ");
        exist=true;
        error=0;
        entrarCadena(cadena,sizeof(cadena));
        exist=existeixDisfressa(cadena,armari);
        if (exist==true) error=1;
    } while (error!=0);
    
    strcpy(armari[pos].nom,cadena);
}

bool existeixDisfressa(char cadena[], DISFRESSA armari[])
{

    bool esIgual=false;
    int i=0;

    i=0;
    while (esIgual==false && i<MAXARMARI)
    {
        if (armari[i].utilitzat==true)
        {
            if (strcmpi(cadena,armari[i].nom)==0)
            {
                esIgual=true;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return esIgual;
}

void introdueixParts(DISFRESSA armari[], int pos)
{
    int num=0;
    do
    {
        num=0;
        armari[pos].parts.totalParts=0;
        printf("Has comprat el traje? (0-1) ");
        num=demanarNumeroMinMax(0,1);
        if (num==1) armari[pos].parts.vestit=true;
        else armari[pos].parts.vestit=false;
        if (armari[pos].parts.vestit==true)
        {
            armari[pos].parts.totalParts++;
        }
        
        printf("Has comprat la gorra? (0-1) ");
        num=demanarNumeroMinMax(0,1);
        if (num==1) armari[pos].parts.gorra=true;
        else armari[pos].parts.gorra=false;

        if (armari[pos].parts.gorra==true)
        {
            armari[pos].parts.totalParts++;
        }

        printf("Has comprat les sabates? (0-1) ");
        num=demanarNumeroMinMax(0,1);
        if (num==1) armari[pos].parts.sabates=true;
        else armari[pos].parts.sabates=false;
        if (armari[pos].parts.sabates==true)
        {
            armari[pos].parts.totalParts++;
        }
        if(armari[pos].parts.totalParts==0)
        {
            printf("No pots tenir una disfressa sense Parts\n");
        }
        
        
    } while (armari[pos].parts.totalParts==0);
}

void mostraArmari(DISFRESSA armari[])
{
    for (int i = 0; i < MAXARMARI; i++)
    {
        if (armari[i].utilitzat==true)
        {
            printf("\n[%d]: %-15s %.2f   T:", i, armari[i].nom, armari[i].preu);
            posSioNo(armari[i].parts.vestit);
            printf("  G:");
            posSioNo(armari[i].parts.gorra);
            printf("  S:");
            posSioNo(armari[i].parts.sabates);
            if (armari[i].qttValo>0)
            {
                armari[i].valoMitja=calculaValoMitja(armari[i].valoracions,armari[i].qttValo);
                printf("  [%.2f]: [",armari[i].valoMitja);
                imprimeixValoracions(armari[i].valoracions,armari[i].qttValo);
                printf("]");
            }
            else
            {
                printf("  No hi ha cap Valoracio");
            }
        }
        else
        {
            setColor(RED);
            printf("\n[%d]: Posicio Buida", i);
            setColor(WHITE);
        }
        
    }
    
}

void posSioNo(bool sioNo)
{
    if (sioNo==true) printf("[Si]");
    else printf("[No]");
}

float calculaValoMitja(int valoracions[], int qtt)
{
    float mitja;
    for (int i = 0; i < qtt; i++)
    {
        mitja=mitja+valoracions[i];
    }
    mitja=mitja/qtt;
    return mitja;
}

void imprimeixValoracions(int v[], int qtt)
{
    for (int i = 0; i < qtt; i++)
    {
        printf("%d ", v[i]);
        if (i+1<qtt)
        {
            printf("- ");
        }
    }
}

void insertaValoracions(DISFRESSA armari[])
{
    mostraArmari(armari);
    getch();
    cls();
    printf("Cal indicar la valoracio de cadascuna de les disfresses de Mario: \n");
    for (int i = 0; i < MAXARMARI; i++)
    {
        if (armari[i].utilitzat==true)
        {
            if (armari[i].qttValo<5)
            {
                printf("Indica la valoracio del la disfresa: %s [0..5]: ", armari[i].nom);
                armari[i].valoracions[armari[i].qttValo]=demanarNumeroMinMax(0,5);
                armari[i].qttValo++;
            }
            else
            {
                printf("La disfresa %s ja te el maxim de Valoracions\n",armari[i].nom);
            }
        }        
    }
    mostraArmari(armari);
}

void donarBaixaDisfressa(DISFRESSA armari[])
{
    char cadena[MIDA];
    int pos=-1;
    bool exist=true;
    mostraArmari(armari);
    do
    {
        if (exist==false) printf("\nIntrodueix una Disfressa que existeixi: ");
        else printf("\nIntrodueix el nom d'una Disfressa: ");
        entrarCadena(cadena,sizeof(cadena));
        exist=true;
        exist=existeixDisfressa(cadena,armari);
    } while (exist==false);

    pos=buscaPosDisfressaNom(armari,cadena);
    armari[pos].utilitzat=false;
}

int buscaPosDisfressaNom(DISFRESSA armari[],char cadena[])
{
    int i=0;
    int pos=-1;
    while (i<MAXARMARI && pos<0)
    {
        if (armari[i].utilitzat==true)
        {
            if (strcmpi(cadena,armari[i].nom)==0)
            {
                pos=i;
            }
            else i++;
        }
        else i++;
    }
    return pos;
}

