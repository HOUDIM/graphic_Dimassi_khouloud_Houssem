#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "entree_sortie.h"
#include "animation.h"

/**************************EXERCICE_2**************************/

void TP2_EX2()
{
    int n,i;
    float S;
    n=saisie_n(3,"N ( N > 2 ) : \0");
    for(S=0,i=1;i<=n;i++)
        S+=(float)1/pow(i,2);
    textcolor(9);
    printf("\n\n");
    animation(" La somme est egale a ");
    printf("%f \n\n\n",S);
    Sleep(700);
    textcolor(8);
}

/**************************EXERCICE_3**************************/

void TP2_EX3()
{
    int n,i;
    float S,S1,S2;
    n=saisie_n(3,"N ( N > 2 ) : \0");
     for(S=0,i=1;i<=n;i++)
        if (i%2==0)
            S-=(float)1/pow(i,2);
        else
            S+=(float)1/pow(i,2);
    textcolor(9);
    printf("\n\n");
    animation(" La somme est egale a ");
    printf("%.4f \n\n\n",S);
    Sleep(700);
    textcolor(8);
}

/**************************EXERCICE_4**************************/

void TP2_EX4()
{
    int n,i,j;
    char s;
    char c;
    n=saisie_n(2,"N ( N > 1 ) : \0");
    for (i=1,j=0;i<=n;i++)
    {
          int a,b;
          a=0; b=0;
          do
          {
           printf("\n\n Donner le %i%c entier positif de 4 chiffres: ",i,c=i>1?'eme':'er');
           textcolor(9);
           scanf("%d",&a);
           textcolor(1);
          } while ( !((a < 10000) && (a > 999))  );
          b=a/1000;
           if (b!=0)
               if (((a%10)%b==0) && (((a%100)/10)%b==0) && (((a%1000)/100)%b==0))
                   {
                       j+=1;
                       textcolor(9);
                       printf("\n\n\t\t %d ",a);animation("est un entier valable \n");
                       textcolor(1);
                   }
    }
    textcolor(2);
    printf("\n\n\t Il y a %d entier%c valable%c dans la suite. \n\n\n",j,s=j>1?115:32,s=j>1?115:32);
    Sleep(700);
    textcolor(8);
}

/**************************EXERCICE_5**************************/

void TP2_EX5()
{
    int x,i,s,j,ok,test=0;
    x=saisie_n(2,"X ( X > 1) : \0");
    s=x;
    textcolor(3);
    animation("\n La decomposition de l'entier "),printf("%i ",x);animation("en facteurs premiers est : \n");
    textcolor(9);
    printf("\n\t %d = ",x);
    for (ok=0,i=2;i<=x;i++)
        for (j=2;j<=i;j++)
    {
         if (i%j==0 &&i==j)
        {
            while (s%i==0)
            {
                if(ok==0)
                        printf(" %d ",i);
                else
                    {
                        printf(" * %d",i);
                        test=1;
                    }
                s=s/i;
                ok=1;
            }
        }
    }
    if (test==0)
        printf("\n\n %i est un entier premier.",x);
    printf("\n\n");
    textcolor(0);
}

/**************************EXERCICE_6**************************/

void TP2_EX6()
{
    int tst=0,a,b,i,ok=1,r=0,s,j,n,m;
    a=saisie_n(100,"A ( A >= 100 ) : \0");
    b=saisie_b(a);
    for (i=a;i<=b;i++)
    {
        m=i;
        s=0;
        while (m!=0)
        {
            n=m%10;
            s=s*10+n;
            m=m/10;
            if( s == i )
            {
                for(j=2,ok=1;j<=i/2;j++)
                    if(i%j==0)
                    {
                        ok=0;
                        r=1;
                        break;
                    }
                if (ok)
                {
                    textcolor(1);
                    printf("\n %d ",i);
                    textcolor(3);
                    printf("est un entier palindrome-premier.\n");
                    tst++;
                    textcolor(1);
                    r=0;
                }
            }
        }
    }
    if (ok==0&&tst==0)
    {
        textcolor(12);
        printf("\n Il n'y a pas des entiers palindrome-premiers entre %d et %d.\n",a,b);
    }
    printf("\n");
    Sleep(500);
    textcolor(8);
}

/**************************EXERCICE_7**************************/

int TP2_EX7()
{
    int x,ok=1,p=1,n;
    n = saisie_n(11,"NB ( NB > 10 ) : ");
    x=n;
    while(x)
    {
        if((((x%10)%2==0)&&(p%2==1))||(((x%10)%2==1)&&(p%2==0)))
           {

            ok=0;
            break;
           }
        else
        {
        p++;
        x=x/10;
        }
    }
    if (ok==1)
    {
        textcolor(2);
        printf("\n%d est toalement impair\n\n",n);
    }
    else
    {
        textcolor(12);
        printf("\n%d n'est pas totalement impaire\n\n",n);
    }
    textcolor(8);
}

/**************************EXERCICE_8**************************/
/**************************QUESTION_1**************************/

void TP2_EX8_Q1()
{
    int  x, i, ok;
    x=saisie_n(2,"X ( X > 1 ) : \0");
    for(i=2, ok=1; i<=x/2;i++)
        if(x%i==0)
        {
            ok=0;
            break;
        }

    if(ok)
        {
            textcolor(2);
            printf("\n L'entier %d est premier.\n\n",x);
        }
    else
        {
            textcolor(12);
            printf("\n L'entier %d n'est pas premier.\n\n",x);
        }
    textcolor(8);
}

/**************************QUESTION_2**************************/

void TP2_EX8_Q2()
{
    int   i=2, ok , cp=0,j,k;
    textcolor(1);
    printf("\n\n Les 10 premiers entiers premiers sont : \n\n");
    textcolor(0);
    for (k = 0; k < 10; k++)
        printf("+-----");
    puts("+");
    printf("| ");
    textcolor(1);
    do
    {
        for(j=2, ok=1; j<=i/2;j++)
            if(i%j==0)
            {
                ok=0;
                break;
            }
        if(ok)
            if (i<10)
            {
                textcolor(3);
                printf(" %d",i);
                textcolor(0);
                printf("  | ");
                textcolor(1);
                cp++;
            }
            else
            {
                printf(" %d",i);
                textcolor(0);
                printf(" | ");
                textcolor(1);
                cp++;
            }
        i++;
    }while(cp!=10);
    textcolor(0);
    printf("\n");
    for (k = 0; k < 10; k++)
        printf("+-----");
    puts("+");
    textcolor(1);
    printf("\n\n");
    textcolor(0);
}

/**************************QUESTION_3**************************/

void TP2_EX8_Q3()
{
    int  n,m,r=1,j, i, ok;
    n=saisie_n(2,"N ( N > 1 ) : \0");
    m=saisie_m(n,1000,"M\0");
    printf("\n");
    gotoxy(1,26);
    for(i=n ; i<=m ; i++)
    {
        for(j=2, ok=1; j<=i/2;j++)
        if(i%j==0)
        {
            ok=0;
            break;
        }
        if(ok)
            {
                textcolor(9);
                printf(" %d",i);
                textcolor(0);
                printf(" |");
                textcolor(1);
                r=0;
            }
    }
    if (ok==0 && r==1)
    {
        textcolor(12);
        printf("\n Pas d'entiers premiers entre %d et %d.",n,m);
    }
    else
    {
        textcolor(2);
        gotoxy(1,23);printf("Les entiers premiers entre %d et %d sont : \n",n,m);
    }
    printf("\n\n\n");
    textcolor(0);
    gotoxy(1,38);

}

/**************************EXERCICE_9**************************/

int TP2_EX9()
{
    int a, b, d=0, i,r,s,x=0;
    a=saisie_a9();
    b=saisie_m(a,500,"B\0");
    printf("\n\n\n\n");
    for(i=a ; i<=b ; i++)
    {
        x=i;
        do
        {
            s=0;
            while(x!=0)
            {
                r=x%10;
                s=s+r*r;
                x=x/10;
            }
            x=s;

        }while(x>9);

        if(x==1)
        {
            if (d==0)
            {
              printf("\n");
              textcolor(0);
              printf("| ");
              textcolor(9);
              printf("%d",i);
              textcolor(0);
              printf(" | ");
              textcolor(9);
              d=1;

            }
            else
            {
                textcolor(9);
                printf("%d",i);
                textcolor(0);
                printf(" | ");
                textcolor(1);
            }
         }
    }

    if (d!=1)
    {
        textcolor(12);
        printf("\n Pas d'entiers heuruex entre %d et %d.",a,b);
    }
    else
    {
        textcolor(2);
        gotoxy(1,22);printf(" Les entiers heureux entre %d et %d sont : \n\n",a,b);
    }
    printf("\n\n\n\n\n\n\n");
    textcolor(0);
}

#endif // TP2_H_INCLUDED
