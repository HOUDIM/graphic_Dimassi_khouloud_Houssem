#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <myconio.h>
#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include "entree_sortie.h"
#include "TP2.h"
#include "TP3.h"
#include "TP4.h"


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("My Project_DIMASSI Houssem_DIMASSI Khouloud"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/

    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {
        case 1: ShellExecute(NULL,"open","TP2.pdf",NULL,NULL,SW_SHOWNORMAL);break;
        case 2: ShellExecute(NULL,"open","TP3.pdf",NULL,NULL,SW_SHOWNORMAL);break;
        case 3: ShellExecute(NULL,"open","TP4.pdf",NULL,NULL,SW_SHOWNORMAL);break;
        case 4:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 2  \n\n\n");
                TP2_EX2();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 5:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 3  \n\n\n");
                TP2_EX3();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 6:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 4  \n\n\n");
                TP2_EX4();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 7:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 5  \n\n\n");
                TP2_EX5();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 8:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 6  \n\n\n");
                TP2_EX6();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 9:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 7  \n\n\n");
                TP2_EX7();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 10:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 8  \n\n\t\t\tQUESTION 1 \n\n\n");
                TP2_EX8_Q1();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 11:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 8  \n\n\t\t\tQUESTION 2 \n\n\n");
                TP2_EX8_Q2();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 12:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 8  \n\n\t\t\tQUESTION 3 \n\n\n");
                TP2_EX8_Q3();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 13:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 2 \n\n\t\t\tEXERCICE 9  \n\n\n");
                TP2_EX9();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 14:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 1  \n\n\t\t\tQUESTION 1 \n\n\n");
                TP3_EX1_Q1();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 15:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 1  \n\n\t\t\tQUESTION 2 \n\n\n");
                TP3_EX1_Q2();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 16:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 1  \n\n\t\t\tQUESTION 3 \n\n\n");
                TP3_EX1_Q3();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 17:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 1  \n\n\t\t\tQUESTION 4 \n\n\n");
                TP3_EX1_Q4();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 18:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 1  \n\n\t\t\tQUESTION 5 \n\n\n");
                TP3_EX1_Q5();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 19:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 1  \n\n\t\t\tQUESTION 6 \n\n\n");
                TP3_EX1_Q7();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 20:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 2  \n\n\t\t\tQUESTION 1 \n\n\n");
                TP3_EX2_Q1();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 21:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 2  \n\n\t\t\tQUESTION 2 \n\n\n");
                TP3_EX2_Q2();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 22:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 2  \n\n\t\t\tQUESTION 3 \n\n\n");
                TP3_EX2_Q3();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 23:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 2  \n\n\t\t\tQUESTION 4 \n\n\n");
                TP3_EX2_Q4();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 24:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 3 \n\n\n");
                TP3_EX3();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 25:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 4 \n\n\n");
                TP3_EX4();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 26:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 5 \n\n\n");
                TP3_EX5();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 27:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 6 \n\n\n");
                TP3_EX6();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 28:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("   TP 3 \n\n\t\t\tEXERCICE 7 \n\n\n");
                TP3_EX7();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 29:
                system("color F3");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(43,3);
                printf("   TP 4\n\n                       ELECTION DE L'ASSEMBLEE DES REPRESENTANTS DU PEUPLE\n\n");
                TP4();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 30:
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;
        }
    case WM_CREATE :
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"PL.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {
         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU henonce=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU htp3=CreateMenu();
    HMENU hex8=CreateMenu();
    HMENU htp4=CreateMenu();
    HMENU hex1=CreateMenu();
    HMENU hex2=CreateMenu();



    //AppendMenu(hmenu,MF_STRING,0,"création du repertoire");
    /*******************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)henonce,"ENONCE TP");
        AppendMenu(henonce,MF_STRING,1,"TP 2");
        AppendMenu(henonce,MF_STRING,2,"TP 3");
        AppendMenu(henonce,MF_STRING,3,"TP 4");
/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"TP2");
        AppendMenu(htp2,MF_STRING,4,"EXERCICE 2");
        AppendMenu(htp2,MF_STRING,5,"EXERCICE 3");
        AppendMenu(htp2,MF_STRING,6,"EXERCICE 4");
        AppendMenu(htp2,MF_STRING,7,"EXERCICE 5");
        AppendMenu(htp2,MF_STRING,8,"EXERCICE 6");
        AppendMenu(htp2,MF_STRING,9,"EXERCICE 7");
        AppendMenu(htp2,MF_POPUP,(UINT_PTR)hex8,"EXERCICE 8");
            AppendMenu(hex8,MF_STRING,10,"QUESTION 1"); /*Sous partie de l'ex8*/
            AppendMenu(hex8,MF_STRING,11,"QUESTION 2");
            AppendMenu(hex8,MF_STRING,12,"QUESTION 3");
        AppendMenu(htp2,MF_STRING,13,"EXERCICE 9");
/***************************************************************/

     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3,"TP3");
        AppendMenu(htp3,MF_POPUP,(UINT_PTR)hex1,"EXERCICE 1");
            AppendMenu(hex1,MF_STRING,14,"QUESTION 1");
            AppendMenu(hex1,MF_STRING,15,"QUESTION 2");
            AppendMenu(hex1,MF_STRING,16,"QUESTION 3");
            AppendMenu(hex1,MF_STRING,17,"QUESTION 4");
            AppendMenu(hex1,MF_STRING,18,"QUESTION 5");
            AppendMenu(hex1,MF_STRING,19,"QUESTION 6");

        AppendMenu(htp3,MF_POPUP,(UINT_PTR)hex2,"EXERCICE 2");
            AppendMenu(hex2,MF_STRING,20,"QUESTION 1");
            AppendMenu(hex2,MF_STRING,21,"QUESTION 2");
            AppendMenu(hex2,MF_STRING,22,"QUESTION 3");
            AppendMenu(hex2,MF_STRING,23,"QUESTION 4");
      AppendMenu(htp3,MF_STRING,24,"EXERCICE 3");
      AppendMenu(htp3,MF_STRING,25,"EXERCICE 4");
      AppendMenu(htp3,MF_STRING,26,"EXERCICE 5");
      AppendMenu(htp3,MF_STRING,27,"EXERCICE 6");
      AppendMenu(htp3,MF_STRING,28,"EXERCICE 7");
/***************************************************************/
    AppendMenu(hmenu,MF_STRING,29,"TP4");

/***************************************************************/
    AppendMenu(hmenu,MF_STRING,30,"Quitter");
    SetMenu(hwnd,hmenu);
}

