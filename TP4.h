#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED
#include <stdio.h>
#include "entree_sortie.h"
#include "affichage_voix.h"

/***********************Question_1***********************/

int saisie_voix(int Voix[][max],int *l,int *c,char *a)
{
    int i,j,x,y,f,w=0;
    FILE *fp;
    fp= fopen("voix.txt","r");
    if(fp != NULL)
    {
        fscanf(fp,"%d\n",&y);
        fscanf(fp,"%d\n",&f);
        if(y && f)
        {
            w=1;
            for(i=1;i<=y;i++)
                for(j=1;j<=f;j++)
                {
                    fscanf(fp,"%d ",&x);
                    Voix[i-1][j-1]=x;
                }
            *l=y;
            *c=f;
        }
    }
    else
        printf("\n Fichier vide \n");
    return w;
}

void init_sieges (int Sieges[][max],int l,int c)
{
    int i,j;
        for(i=0;i<l;i++)
            for(j=0;j<c;j++)
                Sieges[i][j]=0;
}

void init_quotient(int quotient_electoral[],int c)
{
    int i;
        for(i=0;i<c;i++)
            quotient_electoral[i]=1;
}

/***********************Question_2***********************/

void calculQuotient ( int Voix[][max],int l,int c,int quotient_electoral[])
{
    int i,j,total_voix;
        for(i=0;i<l;i++)
        {
            total_voix=0;
            for(j=0;j<c-1;j++)
            {
                total_voix+= Voix[i][j] ;
            }
            quotient_electoral[i] = total_voix/Voix[i][c-1] ;
        }
}

/***********************Question_3***********************/

int nbSieges(int nbVoix , int quotient_electoral)
{
    int nbSiege;
        nbSiege = nbVoix / quotient_electoral;
        return nbSiege;
}

/***********************Question_4***********************/

void affectation ( int Voix[][max],int l,int c,int Sieges[][max],int quotient_electoral[])
{
    int i,j,nb;
        for(i=0;i<l;i++)
        {
            nb=0;
            for(j=0;j<c-1;j++)
            {
                nb = nbSieges(Voix[i][j],quotient_electoral[i]);
                Sieges[i][j]=nb;
                while(nb>0)
                {
                    Voix[i][j] -= quotient_electoral[i];
                    nb--;
                }
            }
            Sieges[i][c-1]=Voix[i][c-1];
        }
}

/***********************Question_5***********************/

int _max (int t[],int n)
{
    int i,_max,pos_max=0;
    _max=t[0];
    for (i=1;i<n;i++)
        if (t[i] > _max )
        {
            _max = t[i];
            pos_max=i;
        }
return pos_max;
}

/***********************Question_6***********************/

void mettreAjour (int Voix[][max],int l,int c, int Sieges[][max])
{
    int i,j,nb,sg,som,t[max];
    for(i=0;i<l;i++)
    {
        som=0;
        for(j=0;j<c-1;j++)
        {
            som+=Sieges[i][j];
            t[j]= Voix[i][j];
        }
        sg = Voix[i][c-1] - som;
        nb = 0;
        while (sg > 0 )
        {
            nb = _max(t,c);
            t[nb]=-1;
            Sieges[i][nb] += 1;
            sg--;
        }
    }
}

/***********************Question_7***********************/

void somme (int Sieges[][max],int l ,int c)
{
    int i,j,s,t[max],k,nb=0;
    k=(c-1);
    for (i=0;i<c-1;i++)
    {
        s=0;
        for (j=0;j<l;j++)
        {
            s += Sieges[j][i];
        }
        t[i] = s;
    }
    while (k>0)
    {
        nb = _max(t,c-1);
        switch(nb)
        {
            case 0: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |  Annahtha  |   %d Sieges   |\n",t[nb]);break ;
            case 1: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |  TAILLAR   |   %d Sieges   |\n",t[nb]);break ;
            case 2: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |    UDL     |   %d Sieges   |\n",t[nb]);break ;
            case 3: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |   FrontP   |   %d Sieges   |\n",t[nb]);break ;
            case 4: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |    JOMH    |   %d Sieges   |\n",t[nb]);break ;
            case 5: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |    PDM     |   %d Sieges   |\n",t[nb]);break ;
            case 6: textcolor(0);printf("    +------------+---------------+\n");
                    textcolor(1);printf("    |   AFEK     |   %d Sieges   |\n",t[nb]);
                    textcolor(0);printf("    +------------+---------------+\n");break ;
        }
        t[nb]=-1;
        k--;
    }
}

void TP4()
{
    int c, l,nbS;
    char a,b;
    int Voix[max][max] , Sieges[max][max] ,quotient_electoral[max];
    textcolor(1);
    saisie_voix(Voix,&l,&c,&a);
    init_sieges(Sieges,l,c);
    init_quotient(quotient_electoral,l);
    textcolor(3);
    animation("\n\n\n      /*************************CHARGEMENT_DE_LA_MATRICE_DES_VOIX*************************/\n\n\n");
    affiche_mat_tp4(Voix,l,c,12);
    calculQuotient(Voix,l,c,quotient_electoral);
    affectation(Voix,l,c,Sieges,quotient_electoral);
    mettreAjour(Voix,l,c,Sieges);
    textcolor(3);
    animation("\n\n\n      /*************************CHARGEMENT_DE_LA_MATRICE_DES_SIEGES*************************/\n\n\n");
    affiche_mat_tp4(Sieges,l,c,68);
    textcolor(3);
    animation("\n\n\n  LE NOMBRE DE SIEGES REMPORTES PAR CHAQUE PARTI POLITIQUE : \n\n\n");
    somme(Sieges,l,c);
    printf("\n\n\n");
    Sleep(700);
    textcolor(8);
}


#endif // TP4_H_INCLUDED
