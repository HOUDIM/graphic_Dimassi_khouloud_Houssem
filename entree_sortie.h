#ifndef ENTREE_SORTIE_H_INCLUDED
#define ENTREE_SORTIE_H_INCLUDED
#include <string.h>
#include <limits.h>
#define max 50

/*****************************************************************/
/****************************** TP_2 *****************************/
/*****************************************************************/

int saisie_n(int a,char x[20])
{
    int n;
    do
     {
         textcolor(1);printf("\n");
         animation(" Donner un entier non nul "); animation(x);
         textcolor(9);
         scanf("%d",&n);
         textcolor(1);
     }while(n<=a-1);
     return n;
}

int saisie_b(int a)
{
    int b;
    do
    {
        textcolor(1);printf("\n");
        animation(" Donner un entier B (B > A) : ");
        textcolor(9);
        scanf("%d",&b);
        textcolor(1);
    }while(!(a<b));
    return b;
}

int saisie_m(int n,int x,char y[10])
{
    int m;
    do
    {
        textcolor(1);printf("\n");
        animation(" Donner un entier ");
        printf("%s ( > %d et <= %d ) : ",y,n,x);
        textcolor(9);
        scanf("%d",&m);
        textcolor(1);
    }while(!(m>n && m<=x));
}

int saisie_a9()
{
    int a;
    do
    {
        textcolor(1);printf("\n\n");
        animation(" Donner un entier A ( A >= 50) : ");
        textcolor(9);
        scanf("%d",&a);
        textcolor(1);
    }while(!(a>=50 && a<=500));
    return a;
}



/*****************************************************************/
/****************************** TP_3 *****************************/
/*****************************************************************/

int saisir_a()
{
    int a;
    textcolor(1);
    animation(" Donner une valeur quelconque : ");
    textcolor(9);
    scanf("%d",&a);
    printf("\n");
    textcolor(1);
    return a;
}

/**********************FONCTION SAISIE_TAILLE**********************/
int saisie_taille(char y[20])
{
    int x;
    do
    {
        printf("\n");
        textcolor(1);
        animation(" Donner la taille du tableau ");
        printf("%s ( > 1 et < %i ) : ",y,max);
        textcolor(9);
        scanf("%d",&x);
    }while(!((x>1)&&(x<=max)));
    printf("\n");
    textcolor(1);
    return x;
}

int saisir_taille_matrice(char msg[20])
{
    int n;
    {
        textcolor(1);printf("\n");
        animation(" Donner le nombre des ");animation(msg);animation(" de la matrice ");printf("( > 1 && < %d ) : ",max);
        textcolor(9);
        scanf("%d",&n);
        textcolor(1);
        printf("\n");
    }while (!(n>1&&n<max));
    return n;
}

/**********************FONCTION REMPLIR**********************/

void remplir_tab( int t1[],int n1)
{
    int i;
    textcolor(3);
    animation("****** CHARGEMENT DU TABLEAU ******\n\n");
    textcolor(1);
    for (i=0; i<n1;i++)
    {
        printf("t1[%d] : ",i);
        textcolor(9);
        scanf("%d",&t1[i]);
        textcolor(1);
    }
    printf("\n");
}

void remplir_tab_3CH( int t1[],int n1)
{
    int i;
    textcolor(3);
    animation("****** CHARGEMENT DU TABLEAU ******\n\n");
    textcolor(1);
    for (i=0; i<n1;i++)
    {
        do
        {
            printf("t1[%d] : ",i);
            textcolor(9);
            scanf("%d",&t1[i]);
            textcolor(1);
        }while (!(t1[i]>99&&t1[i]<1000));
    }
    printf("\n");
}

int recherche (int t[], int i, int x)
{
    int j;
    for (j=0;j<i;j++)
        if (t[j]==x)
            return 1;
    return 0;
}

void remplir_tab_sans_r(int t[],int n)
{
    int i;
    textcolor(3);
    animation("****** CHARGEMENT DU TABLEAU ******\n\n");
    textcolor(1);
    for (i=0;i<n;i++)
    do
    {
        printf("T[%d] : ",i);
        textcolor(9);
        scanf("%d",&t[i]);
        textcolor(1);
    }while (!(t[i]>0 && recherche (t,i,t[i])==0));
}

void remplir_mat(int m[max][max],int l,int c)
{
    int i,j;
    textcolor(3);
    animation("****** CHARGEMENT DE LA MATRICE M ******\n\n");
    textcolor(1);
    for (i=0;i<l;i++)
        for (j=0;j<c;j++)
    {
        printf("M[%d][%d] : ",i,j);
        textcolor(9);
        scanf("%d",&m[i][j]);
        textcolor(1);
    }
}


/**********************FONCTION AFFICHER**********************/

void affiche_tab(int t1[], int n)
{
    int i,j,k;
    textcolor(3);
    animation("****** AFFICHAGE DU TABLEAU ******\n\n");
    textcolor(0);
    for (j = 0; j < n; j++)
        printf("+---");
    puts("+");
    printf("| ");
    textcolor(1);
    for(k = 0;k < n;k++)
    {
        printf("%d",t1[k]);
        textcolor(0);
        printf(" | ");
        textcolor(1);
    }
    printf("\n");
    textcolor(0);
    for (i = 0; i < n; i++)
        printf("+---");
    puts("+");
    textcolor(1);
    printf("\n");
}

void affiche_tab_tri(int t1[], int n)
{
    int i,j,k;
    textcolor(3);
    animation("****** AFFICHAGE DU TABLEAU T APRES TRI ******\n\n");
    textcolor(0);
    for (j = 0; j < n; j++)
        printf("+----");
    puts("+");
    printf("| ");
    textcolor(1);
    for(k = 0;k < n;k++)
    {
        printf("%d",t1[k]);
        textcolor(0);
        printf(" | ");
        textcolor(1);
    }
    printf("\n");
    textcolor(0);
    for (i = 0; i < n; i++)
        printf("+----");
    puts("+");
    textcolor(1);
    printf("\n");
}

void affiche_tab_3CH(int t1[], int n)
{
    int i,j,k;
    textcolor(3);
    animation("****** AFFICHAGE DU TABLEAU ******\n");
    textcolor(0);
    for (j = 0; j < n; j++)
        printf("+-----");
    puts("+");
    printf("| ");
    textcolor(1);
    for(k = 0;k < n;k++)
    {
        printf("%d",t1[k]);
        textcolor(0);
        printf(" | ");
        textcolor(1);
    }
    printf("\n");
    textcolor(0);
    for (i = 0; i < n; i++)
        printf("+-----");
    puts("+");
    textcolor(1);
    printf("\n");
}

void affiche_pos(int t1[], int n1,int y)
{
    int i,j,k;
    textcolor(3);
    printf("\n****** AFFICHAGE DU TABLEAU ******\n\n");
    textcolor(0);
    for (j = 0; j < n1; j++)
        printf("+---");
    puts("+");
    printf("| ");
    textcolor(1);
    for(i=0;i<n1;i++)
        if (i==y)
    {
        textcolor(13);
        printf("%d",t1[i]);
        textcolor(0);
        printf(" | ");
        textcolor(1);
    }
    else
    {
        printf("%d",t1[i]);
        textcolor(0);
        printf(" | ");
        textcolor(1);
    }
    printf("\n");
    textcolor(0);
    for (k = 0; k < n1; k++)
        printf("+---");
    puts("+");
    textcolor(1);
    printf("\n");
}

void affiche_mat(int m[max][max],int l,int c)
{
    int i,j,k;
    textcolor(3);
    animation("\n****** CONTENU DE LA MATRICE M ******\n\n");
    textcolor(1);
    for (k = 0; k < c; k++)
        {
            textcolor(0);
            printf("+---");
        }
    puts("+");
    textcolor(0);
    for (i=0;i<l;i++)
    {
        for (j=0;j<c;j++)
        {
            textcolor(0);
            printf("|");
            textcolor(1);
            printf(" %d ",m[i][j]);
        }
        textcolor(0);
        printf("|");
        textcolor(1);
        printf("\n");
        for (k = 0; k < c; k++)
        {
            textcolor(0);
            printf("+---");
        }
        puts("+");
    }
}

#endif // ENTREE_SORTIE_H_INCLUDED
