#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int preguntaOpcio()
{
    char opcionsMenu[SORTIR][40] = {"Afegir Resposta",
                                    "Mostrar Respostes",
                                    "Sortir"};

    int op;
    printf("MENU:\n");
    for (int i = 0; i < SORTIR; i++)
    {
        printf("%d.- %s\n", i + 1, opcionsMenu[i]);
    }

    printf("\nIntrodueix quina opcio vols fer? [%d-%d]: ", 1, SORTIR);
    op=demanarNumeroMinMax(AFEGIR, SORTIR);
    return op;
}

void creaArxiuCorrecte(int qttPreguntes)
{
    char fitxer1[]="./fitxers/respostes_ok.txt";
    FILE *f;
    int numero;
    char letra;

    f=obrirFitxer(fitxer1,"w");

    for (int i = 0; i < qttPreguntes; i++)
    {
        numero=RandomizadorNumeros(65,68);
        letra=numero;
    	fprintf(f,"%d\n",i+1);
        if (i+1==qttPreguntes) fprintf(f,"%c",letra);
        else fprintf(f,"%c\n",letra); 
    }
    fclose(f);
}

void responAlumne(int qttPreguntas,char fitxer1[])
{
    bool sortir=false;
    PREGUNTES pregunta;
    int respuesta1;
    int modificar;
    int cosa;
    while (sortir!=true)
    {
        cls();
        printf("Que pregunta quieres Responder[1-%d]? ",qttPreguntas);
        pregunta.numPregunta=demanarNumeroMinMax(1,qttPreguntas);

        printf("Estas en la pregunta %d, qual es la respuesta correcta [A-B-C-D]? ",pregunta.numPregunta);
        respuesta1=demanarNumeroMinMax2(65,68);

        pregunta.respostaAlumne=respuesta1;
        while(getchar()!='\n');

        if (existeixFitxer(fitxer1)==true)
        {
            if (contestada(pregunta.numPregunta,fitxer1)==true)
            {
                printf("Esta Pregunta ya ha sido Contestada\nQuieres modificar la respuesta a esta nueva [0-1]? ");
                modificar=demanarNumeroMinMax(0,1);
                if (modificar==1)
                {
                    modificaRespota(pregunta,fitxer1);
                }
                else{printf("La respuesta no se modificara"); Sleep(300);}  
            }
            else
            {
                insertarPreguntaNormal(pregunta,fitxer1);
            }
        }
        else
        {
            insertarPrimeraPregunta(pregunta,fitxer1);
        }
        printf("\n\nQuieres Continuar poniendo respuestas [0-1]? ");
        cosa=demanarNumeroMinMax(0,1);
        if(cosa==0) sortir=true;
        Sleep(200);
    }
    
}

void modificaRespota(PREGUNTES pregunta,char fitxer1[])
{
    FILE *f;
    f=obrirFitxer(fitxer1,"r+");
    char numPregunta[250];
    sprintf(numPregunta, "%d", pregunta.numPregunta);
    numPregunta[strlen(numPregunta)]='\0';
    bool trobat=false;
    char linea[250];
    while(fgets(linea, sizeof(linea), f) != NULL && trobat!=true) 
    {
        eliminaSaltLinia(linea);
        if (strcmpi(linea, numPregunta) == 0) {
            trobat = true;
            fseek(f,0,SEEK_CUR);
            fputc(pregunta.respostaAlumne,f);
            fflush(f);
        }
    }
    fclose(f);
}

void insertarPrimeraPregunta(PREGUNTES pregunta,char fitxer1[])
{
    FILE *f;
    f=obrirFitxer(fitxer1,"w");
    fprintf(f,"%d\n",pregunta.numPregunta);
    fprintf(f,"%c",pregunta.respostaAlumne);
    fclose(f);
}


void insertarPreguntaNormal(PREGUNTES pregunta,char fitxer1[]){
    FILE *f;
    f=obrirFitxer(fitxer1,"a");
    fseek(f,0,SEEK_END);
    fprintf(f,"\n%d\n",pregunta.numPregunta);
    fprintf(f,"%c",pregunta.respostaAlumne);
    fclose(f);
}

bool contestada(int numPregunta, char fitxer[])
{
    FILE *f;
    f=obrirFitxer(fitxer,"r");
    bool sortir=false;
    char numPregunta2[250];
    char linea[250];
    sprintf(numPregunta2, "%d", numPregunta2);
    numPregunta2[strlen(numPregunta2)]='\0';

    while(feof(f)==0 && sortir!=true)
    {
        fgets(linea,sizeof(linea),f);
        eliminaSaltLinia(linea);
        if(strcmpi(linea,numPregunta2)==0) sortir=true;
    }
    fclose(f);
    return sortir;
}

int demanarNumeroMinMax2(int min, int max){
    int numero=min;
    char letra;
    do{
		if (numero < min || numero > max)
		{
			printf("Introduce A, B, C o D Porfavor: ");
		}
        while(getchar()!='\n');
        scanf("%c", &letra);
        letra=toupper(letra);
        numero=toascii(letra);
	}
    while (numero < min || numero > max);
    return numero;
}


void mostrar(char fitxer1[]){
    
    cls();
    if (existeixFitxer(fitxer1)==true)
    {
        FILE *f;
        f=obrirFitxer(fitxer1,"r");
        char numPregunta[255];
        char resposta[255];
        while (feof(f)==0)
        {
            
            fgets(numPregunta,sizeof(numPregunta),f);
            fgets(resposta,sizeof(resposta),f);
            eliminaSaltLinia(numPregunta);
            eliminaSaltLinia(resposta);
            printf("%s %s\n",numPregunta,resposta);
        }
        fclose(f);
    }    
    else printf("No Se han introducido Respuestas");
    getch();
}

void contadores(int contador[],char fitxer1[],char fitxer2[], int qttPreguntas){

    FILE *f;
    FILE *a;
    a=obrirFitxer(fitxer2,"r");
    f=obrirFitxer(fitxer1,"r");
    bool sortir=false;
    char lineaAlumne[255];
    char lineaOk[250];
    fgets(lineaAlumne,sizeof(lineaAlumne),f);
    eliminaSaltLinia(lineaAlumne);
    while (feof(f)==0)
    {
        while(feof(a)==0 && sortir!=true)
        {
            fgets(lineaOk,sizeof(lineaOk),a);
            eliminaSaltLinia(lineaOk);
            if(strcmpi(lineaOk,lineaAlumne)==0) 
            {
                sortir=true;
                fgets(lineaAlumne,sizeof(lineaAlumne),f);
                fgets(lineaOk,sizeof(lineaOk),a);
                eliminaSaltLinia(lineaOk);
                eliminaSaltLinia(lineaAlumne);
                if(strcmpi(lineaOk,lineaAlumne)==0)contador[0]++;
                else contador[1]++;
            }
            else fgets(lineaAlumne,sizeof(lineaAlumne),f);
        }
        sortir=false;
        fgets(lineaAlumne,sizeof(lineaAlumne),f);
        eliminaSaltLinia(lineaAlumne);
    }
    if((contador[1]+contador[0]!=qttPreguntas)) contador[2]=qttPreguntas-((contador[0])+(contador[1]));
}

float calcula(int contador[],int qttPreguntas){
    int puntuacioTotal;
    float puntuacioFinal;
    puntuacioTotal=((contador[0]*1)-(contador[1]*0.3));
    puntuacioFinal=((puntuacioTotal/qttPreguntas)*10);
    return puntuacioFinal;
}


