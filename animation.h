#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <time.h>

void animation(char str[250])
{
    int i;
    int len = strlen(str);
    for(i=0;i<len;i++) {
        putchar(str[i]);
//        usleep(100);//Sleep Microsecond
        Sleep(30);
    }


}


#endif // ANIMATION_H_INCLUDED
