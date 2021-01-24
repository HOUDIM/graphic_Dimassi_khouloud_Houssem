#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#include<limits.h>
#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include<string.h>
#include<limits.h>
#define max 50
#include "entree_sortie.h"

    /**************************EXERCICE_1**************************/
    /**************************QUESTION_1**************************/
/**************************FONCTION_TRANSFERE**************************/

void transfere(int t1[],int t2[],int n1)
{
    int i,j,k;
    for (i=0,j=0,k=n1-1;i<n1;i++)
        if (i%2==1)
    {
        t2[k]=t1[i];
        k--;
    }
    else
    {
        t2[j]=t1[i];
        j++;
    }
}

void TP3_EX1_Q1()
{
    int n,t1[max],t2[max];
    n=saisie_taille("T1\0");
    remplir_tab(t1,n);
    affiche_tab(t1,n);
    transfere(t1,t2,n);
    textcolor(3);
    Sleep(700);
    animation("********* APRES TRANSFERE *********\n\n");
    affiche_tab(t2,n);
    textcolor(8);
    Sleep(800);
}
    /**************************QUESTION_2**************************/
/**************************FONCTION_SYMETRIQUE**************************/

bool symetrique(int t[], int n1)
{
    int i;
        bool ok=true;
        for(i=0;i<n1/2;i++)
            if (t[i]!=t[n1-1-i])
            {
                ok=false;
                break;
            }
    return ok;
}

void TP3_EX1_Q2()
{
    int n,t[max];
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    if (symetrique(t,n))
    {
       textcolor(2);
       Sleep(600);
       animation(" T1 est symetrique");
    }
    else
    {
        textcolor(12);
        Sleep(600);
        animation(" T1 n'est pas symetrique.");
    }
    printf("\n\n\n");
    Sleep(800);
    textcolor(8);
}
    /**************************QUESTION_3**************************/
/**************************FONCTION_INVERSE**************************/

void inverse(int t1[],int n1)
{
    int i, aux;
    for(i=0;i<n1/2;i++)
    {
        aux=t1[i];
        t1[i]=t1[n1-1-i];
        t1[n1-1-i]=aux;
    }
}

void TP3_EX1_Q3()
{
    int n,t[max];
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    inverse(t,n);
    Sleep(700);
    textcolor(3);
    animation("********* APRES INVERSION *********\n\n");
    affiche_tab(t,n);
    textcolor(8);
    Sleep(700);
}
    /**************************QUESTION_4**************************/
/**************************FONCTION_K_ROTATION**************************/

int saisie_k(int n)
{
    int k;
    do
    {
        textcolor(1);
        animation("Donner k: ");
        textcolor(9);
        scanf("%d",&k);
        textcolor(1);
        printf("\n");
    }while (!((k>0)&&(k<=n)));
    return k;
}

void k_rotation(int t1[],int n1,int k)
{
    int i,j,aux;
    for (i=1;i<=k;i++)
    {
        aux=t1[n1-1];
        for(j=n1-1;j>0;j--)
            t1[j]=t1[j-1];
        t1[0]=aux;
    }
}

void TP3_EX1_Q4()
{
    int n,k,t[max];
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    k=saisie_k(n);
    k_rotation(t,n,k);
    Sleep(700);
    textcolor(3);
    animation("********* APRES ROTATION *********\n\n");
    affiche_tab(t,n);
    textcolor(8);
    Sleep(700);
    printf("\n");
}

    /**************************QUESTION_5**************************/
/**************************FONCTION_INSERTION**************************/
int insertion(int t[],int n)
{
    int val,pos;
    animation("Donner une valeur : ");
    textcolor(9);
    scanf("%d",&val);
    textcolor(1);
    do
    {
        animation("\nDonner une position : ");
        textcolor(9);
        scanf("%d",&pos);
        textcolor(1);
    }while (!(pos>=0&&pos<=n-1));
    t[pos]=val;
    return pos;
}

void TP3_EX1_Q5()
{
    int n,k,t[max],pos;
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    pos=insertion(t,n);
    Sleep(700);
    textcolor(3);
    animation("\n\n********* APRES INSERTION *********\n");
    affiche_pos(t,n,pos);
    textcolor(8);
    Sleep(700);
}

    /**************************QUESTION_7**************************/
/**************************FONCTION_MAIN**************************/
void TP3_EX1_Q7()
{
    int t1[max],t2[max],v[max],k,n,m,pos;
    n=saisie_taille("T1\0");
    remplir_tab(t1,n);
    affiche_tab(t1,n);
    transfere(t1,t2,n);
    textcolor(3);
    Sleep(700);
    animation("********* APRES TRANSFERE *********\n\n");
    affiche_tab(t2,n);
    Sleep(700);
    textcolor(3);
    animation("********* APRES INVERSION *********\n\n");
    inverse(t1,n);
    affiche_tab(t1,n);
    if (symetrique(t1,n))
    {
       textcolor(2);
       Sleep(400);
       animation(" T est symetrique");
    }
    else
    {
        textcolor(12);
        Sleep(400);
        animation(" T n'est pas symetrique.");
    }
    printf("\n\n");
    k=saisie_k(n);
    k_rotation(t1,n,k);
    Sleep(400);
    textcolor(3);
    animation("********* APRES ROTATION *********\n\n");
    affiche_tab(t1,n);
    pos=insertion(t1,n);
    Sleep(400);
    textcolor(3);
    animation("\n\n********* APRES INSERTION *********\n");
    affiche_pos(t1,n,pos);
    textcolor(8);
    Sleep(700);
}

    /**************************EXERCICE_2**************************/
    /**************************QUESTION_1**************************/
/**************************FONCTION_RECHERCHE**************************/

int chercher_sup (int t[],int n, int a)
{
    int i,ok=0;
    for (i=0;i<n;i++)
        if (t[i]>a)
            {
                printf(" %d ",t[i]);
                textcolor(0);
                printf("| ");
                textcolor(1);
                ok+=1;
            }
    if (ok==0)
        {
            textcolor(12);
            animation(" Il n'existe pas un element sup a");printf(" %d \n",a);
            textcolor(1);
        }
    return ok;
}

void chercher_petit_sup (int t[], int n, int a)
{
    int i,element_petit=INT_MIN;
        for (i=0;i<n;i++)
        if (t[i]>a)
        {
             if( element_petit == INT_MIN || t[i] < element_petit )
            {
                element_petit=t[i];
            }
        }
        printf("    %d",element_petit);
}

void TP3_EX2_Q1()
{
    int n,t[max],a;
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    a=saisir_a();
    textcolor(3);
    animation("****** LES ELEMENTS SUPERIEURS  ******\n\n");
    textcolor(1);
    if (chercher_sup(t,n,a))
    {
       textcolor(3);
       animation("\n\n****** LE PETIT ELEMENT SUPERIEUR  ******\n\n");
       textcolor(1);
       chercher_petit_sup(t,n,a);
    }
    printf("\n\n");
    Sleep(700);
    textcolor(8);
}

    /**************************QUESTION_2**************************/
/**************************FONCTION_OCCURENCE**************************/

void occurence(int t[], int n)
{
    int i,j,occ;
    int plu, max_occ;
    max_occ=0;
    for (i=0; i<n; i++)
        {
            occ=0;
            for (j=0;j<n;j++)
            {
                if (t[i]==t[j])
                    occ+=1;
            }
            if (occ>max_occ)
               {
                  max_occ=occ;
                  plu=t[i];
               }
        }
      if (max_occ>1)
      {
          textcolor(2);
          printf( " %d",plu),animation(" est l'element qui apparait le plus dans le tableau dont son nombre d'occurence est  ");printf("%d.\n",max_occ);
          textcolor(1);
      }
      else
      {
          textcolor(12);
          animation(" Pas d'occurence.");
          textcolor(1);
      }
}

void TP3_EX2_Q2()
{
    int n,t[max],a;
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    textcolor(3);
    animation("******OCCURENCE******\n\n");
    textcolor(1);
    occurence(t,n);
    printf("\n\n");
    Sleep(700);
    textcolor(8);
}

   /**************************QUESTION_3**************************/
/**************************FONCTION_PLATEAU**************************/

void plateau (int t[], int n)
{
    int l=0,s=0,i,j,l1=1;
    for (i=1;i<=n;i++)
    {
        if (t[i]==t[i-1])
            l1+=1;
         else
            if (l1>l)
            {
                l=l1;
                s=i-l;
                l1=1;
            }
            else
                l1=1;
    }
    if (l>1)
    {
        textcolor(2);
        printf("\n Le plus long plateau commence par %d se termine par %d et de longueur %d.\n",s,s+l-1,l);
        textcolor(1);
    }
    else
    {
        textcolor(12);
        animation("\n Il n'existe pas des plateaux.\n");
        textcolor(1);
    }
}

void TP3_EX2_Q3()
{
    int n,t[max],a;
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    textcolor(3);
    animation("******LE PLUS LONG PLATEAU******\n");
    textcolor(1);
    plateau(t,n);
    printf("\n\n");
    textcolor(8);
    Sleep(700);
}

    /**************************QUESTION_4**************************/
/**************************FONCTION_MAIN**************************/

void TP3_EX2_Q4()
{
    int n,t[max],a;
    n=saisie_taille("T\0");
    remplir_tab(t,n);
    affiche_tab(t,n);
    a=saisir_a();
    textcolor(3);
    animation("\n******LES ELEMENTS SUPERIEURS ******\n\n");
    textcolor(1);
    if (chercher_sup(t,n,a))
    {
       textcolor(3);
       animation("\n\n******LE PETIT ELEMENT SUPERIEUR ******\n\n");
       textcolor(1);
       chercher_petit_sup(t,n,a);
    }
    textcolor(3);
    animation("\n\n******OCCURENCE******\n\n");
    textcolor(1);
    occurence(t,n);
    textcolor(3);
    animation("\n\n******LE PLUS LONG PLATEAU******\n\n");
    textcolor(1);
    plateau(t,n);
    printf("\n\n");
    textcolor(8);
}

    /**************************EXERCICE_3**************************/

void tri (int t[], int n, int b[])
{
    int _max = 0,_pos = 0,last_pos = 0;
    while (_max != -1)
    {
        _max = -1;
        for(int i =0; i<n; ++i)
        {
            if(t[i] > _max)
            {
                _pos = i;
                _max = t[i];
            }
        }
        if(_max != -1)
        {
            b[last_pos++] = _max;
            t[_pos] = -1;
        }
    }
}

void TP3_EX3()
{
    int n, t[max],b[max];
    n=saisie_taille("T\0");
    remplir_tab_sans_r(t,n);
    printf("\n");
    affiche_tab(t,n);
    tri(t,n,b);
    Sleep(700);
    textcolor(3);
    animation("********* APRES TRI *********\n\n");
    affiche_tab_tri(t,n);
    affiche_tab(b,n);
    textcolor(8);
    Sleep(700);
}

    /**************************EXERCICE_4**************************/

int k_pp(int t[],int n)
{
  int x,i,j,cp,test=0;
   for (j=0;j<n;j++)
   {
        x=t[j];
        textcolor(4);
        printf("%d = ",t[j]);
        textcolor(1);
        i=2;
        cp=1;
        do
        {
            if(t[j]%i==0)
            {
                if(cp==1)
                    printf("%d ",i);
                else
                {
                    printf("* %d ",i);
                    test++;
                }
                t[j]=t[j]/i;
                cp++;

            }
            else
                i++;
        }while(t[j]!=1);
        printf("\n\n");
        if ((2<=(test+1))&&((test+1)<=5))
        {
            textcolor(2);
            printf("%d est un %d-pp car il est le produit de %d nombres premiers.\n\n",x,test+1,test+1);
            test=0;
        }
   }
    return 0;
}

void TP3_EX4()
{
    int n, t[max];
    n=saisie_taille("T\0");
    remplir_tab_3CH(t,n);
    affiche_tab_3CH(t,n);
    k_pp(t,n);
    printf("\n");
    textcolor(8);
    Sleep(700);
}

    /**************************EXERCICE_5**************************/

void transpose(int n, int m[max][max], int tr[max][max])
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            tr[i][j] = m[j][i];
}

int symetriquee(int n, int m[max][max])
{
    int tr[max][max];
    transpose(n, m, tr);
    for (int i = 0; i <n; i++)
        for (int j = 0; j <n; j++)
            if (m[i][j] != tr[i][j])
                return 0;
    return 1;
}

void TP3_EX5()
{
    int n, m[max][max];
    n=saisir_taille_matrice("lignes");
    remplir_mat(m,n,n);
    affiche_mat(m,n,n);
    if ( symetriquee(n, m) == 1 )
    {
        textcolor(2);
        animation("\n Elle est symetrique par rapport a la 1er diagonale.\n");
    }
    else
    {
        textcolor(12);
        animation("\n Elle n'est pas symetrique par rapport a la 1er diagonale.\n");
    }
    printf("\n");
    textcolor(8);
    Sleep(700);
}

/**************************EXERCICE_6**************************/

void rech_col(int M[max][max],int l,int c)
{
    int j,i,k,Vtest =0 ,_min,imin, _max;

    for (i=0 ; i<l ; i++)
        {
            _min = M[i][0];
            imin = 0;
            for (j=0 ; j<c ; j++)
                if (_min > M[i][j])
                {
                    _min = M[i][j];
                    imin=j;
                }
            _max = M[0][imin];
            for (k=0 ; k<l ; k++)
            {
                if (_max < M[k][imin])
                    _max = M[k][imin];
            }
            if ( _max == _min)
            {
                Vtest= 1;
                textcolor(2);
                printf("\n M (%d,%d) = %d est un point COL \n\n",i,imin,_max);
                for (j=imin+1;j<c;j++)
                    if (_min == M[i][j])
                    {
                        textcolor(2);
                        printf("\n M (%d,%d) = %d est un point COL \n\n",i,j,_max);
                    }
            }
        }

    if (!(Vtest==1))
    {
        textcolor(12);
        animation("\n M n'a aucun point COL \n\n");
    }

}
void TP3_EX6()
{
    int l,c,m[max][max];
    l=saisir_taille_matrice("lignes\0");
    c=saisir_taille_matrice("colonnes\0");
    remplir_mat(m,l,c);
    affiche_mat(m,l,c);
    rech_col(m,l,c);
    Sleep(700);
    textcolor(8);
}

/**************************EXERCICE_7**************************/

void magique(int m[max][max],int n)
{
    int i,j,x=0,y=0,test=0,sl=0,sc=0,sd=0,sd1=0,tr[max][max];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            sc+=m[i][j];
            sl+=m[j][i];
            if (i==j)
                sd+=m[i][i];
        }
        if (sc==sl)
        {
            test=1;
            x=sc;
            sc=0;
            sl=0;
        }
        else
            break;
    }
    for (int k=0,l=n-1 ; k < n && l >= 0 ; k++,l--)
        sd1+=m[k][l];

    if ((test==1)&&(sd1==sd)&&(sd==x))
        {
            textcolor(2);
            animation("\n\n Cette matrice est magique, car toutes les sommes sont egales a ");printf("%i.\n\n",x);
        }
    else
        {
            textcolor(12);
            animation("\n\n Cette martice n'est pas magique.\n\n");
        }
}
void TP3_EX7()
{
    int n,m[max][max];
    do
    {
        n=saisie_taille("lignes\0");
    }while (!(n%2!=0));
    remplir_mat(m,n,n);
    affiche_mat(m,n,n);
    magique(m,n);
    textcolor(8);
    Sleep(700);
}
#endif // TP3_H_INCLUDED

