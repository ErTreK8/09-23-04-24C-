#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void generar()
{
    ARTICLE molts[5]={{"poma",12},{"taronja",11},{"pera",10},{"platan",9},{"maduixes",8}};
    FILE *f=fopen(UBICACIOARTICLE,"wb");
    if (f!=NULL)
    {
        fwrite(molts,sizeof(ARTICLE),5,f);
        fclose(f);
    }
}

void llegir()
{
    ARTICLE un;
    FILE *f=fopen(UBICACIOARTICLE,"rb");
    if (f!=NULL)
    {
        int qttArticles=calculaTotal(UBICACIOARTICLE,sizeof(ARTICLE));
        for (int i=0;i<qttArticles;i++)
        {
            fread(&un,sizeof(ARTICLE),1,f);
            printf("\n[%d]: %s  %.2f",i+1,un.nom,un.preu);
        }
        fclose(f);
    }
}

int calculaTotal(char nFile[],int longitudUnElement)
{
    int total=0;
    FILE *f=fopen(UBICACIOARTICLE,"rb");
    if (f!=NULL)
    {
        fseek(f,0,SEEK_END);
        total=ftell(f)/longitudUnElement;
        fclose(f);
    }
    return total;
}

void incrementar()
{
    ARTICLE un;
    printf("\n\nQuin element vols incrementar en 100000 el preu? ");
    int index=demanaNumEntreRangInt(1,calculaTotal(UBICACIOARTICLE,sizeof(ARTICLE)));

    FILE *f=fopen(UBICACIOARTICLE,"rb+");
    if (f!=NULL)
    {
        fseek(f,(index-1)*sizeof(ARTICLE),SEEK_SET);
        fread(&un,sizeof(ARTICLE),1,f);
        un.preu=un.preu+100000;
        fseek(f,(index-1)*sizeof(ARTICLE),SEEK_SET);
        //fseek(f,-sizeof(ARTICLE),SEEK_CUR);
        fwrite(&un,sizeof(ARTICLE),1,f);
        fclose(f);
    }
}

void eliminar()
{
    ARTICLE un;
    
    int totalArticles=calculaTotal(UBICACIOARTICLE,sizeof(ARTICLE));

    printf("\n\nQuin element vols eliminar? ");
    int index=demanaNumEntreRangInt(1,totalArticles);

    FILE *f=fopen(UBICACIOARTICLE,"rb");
    if (f!=NULL)
    {
        for (int i=1; i<=totalArticles;i++)
        {
            fread(&un,sizeof(ARTICLE),1,f);
            if (i!=index)
            {
                copiar(un);
            }
        }
        fclose(f);
        remove(UBICACIOARTICLE);
        rename(UBICACIOARTICLEAUXILIAR,UBICACIOARTICLE);
        printf("\nEliminat l'element");
    }
}
void copiar(ARTICLE un)
{
    FILE *f=fopen(UBICACIOARTICLEAUXILIAR,"ab");
    if (f!=NULL)
    {
        fwrite(&un,sizeof(ARTICLE),1,f);
        fclose(f);
    }
}

void girarFitxerAuxiliar()
{
    ARTICLE un;
    int totalArticles=calculaTotal(UBICACIOARTICLE,sizeof(ARTICLE));

    FILE *f=fopen(UBICACIOARTICLE,"rb");
    if (f!=NULL)
    {
        for (int i=totalArticles-1;i>=0;i--)
        {
            fseek(f,i*sizeof(ARTICLE),SEEK_SET);
            fread(&un,sizeof(ARTICLE),1,f);
            copiar(un);
        }
        fclose(f);
        remove(UBICACIOARTICLE);
        rename(UBICACIOARTICLEAUXILIAR,UBICACIOARTICLE);
        printf("\n\nFitxer girat: \n");
        llegir();
    }
}

void girarFitxerSenseAuxiliar()
{
    ARTICLE dalt,baix;
    int totalArticles=calculaTotal(UBICACIOARTICLE,sizeof(ARTICLE));

    FILE *f=fopen(UBICACIOARTICLE,"rb+");
    if (f!=NULL)
    {
        for (int i=0,j=totalArticles-1;i<totalArticles/2;i++,j--)
        {
            //llegint l'article dalt
            fseek(f,i*sizeof(ARTICLE),SEEK_SET);
            fread(&dalt,sizeof(ARTICLE),1,f);

            //llegint l'article de sota
            fseek(f,j*sizeof(ARTICLE),SEEK_SET);
            fread(&baix,sizeof(ARTICLE),1,f);

            //escriure dalt
            fseek(f,i*sizeof(ARTICLE),SEEK_SET);
            fwrite(&baix,sizeof(ARTICLE),1,f);

            //escriure a sota
            fseek(f,j*sizeof(ARTICLE),SEEK_SET);
            printf("\n%s ",dalt.nom);
            fwrite(&dalt,sizeof(ARTICLE),1,f);
            fflush(f);
        }
        fclose(f);
        printf("\n\nFitxer girat: \n");
        llegir();
    }

}