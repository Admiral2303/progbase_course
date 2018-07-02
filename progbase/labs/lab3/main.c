#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <progbase.h>
#include <pbconsole.h>

#include "menu.h"
#include "assert.h"

int main(int argc, char *argv[])
{
    conHideCursor();
    int number = 1000;
    int i = 0;
    int k = 0;
    struct profecional * profs[1000] = {NULL};

    for(int j = 0; j < argc; j++)
    {
        if (strcmp("test",argv[j]) == 0)
        {
            validtesting();
            validtestfloatin();
            check(profs);
            filetest();
            checkdelete();
            checkstruct2();
            checkcopy();
            return 0;
        }
    }
    line();
    printfirstmenu();
    printdots(0);
    while(1)
    {
        k = conGetChar();
        conReset();
        if(k == 'q')
        {
            cleanall();
            cat();
            break;
        }
        switch(k)
        {
        case '1':
            printdots(1);
            clearmainmenu();
            printsecondmenu();
            while(1)
            {
                k = conGetChar();
                conReset();
                if(k == 'q')
                {
                    printdots(0);
                    clearstringtostruct();
                    clearmainmenu();
                    printfirstmenu();
                    break;

                }
                switch(k)
                {
                case '1':
                    clearstringtostruct();
                    stringtostruct(profs);
                    break;
                case '2':
                    clearstringtostruct();
                    printsecondmenu();
                    structtostring(profs);
                    break;
                case '3':
                    clearstringtostruct();
                    clear();
                    texttostruct(profs);
                    break;
                case '4':
                    clearstringtostruct();
                    deletestruct(profs);
                    break;
                case '5':
                    clearstringtostruct();
                    structtotext(profs);
                    break;
                case '6':
                    clearstringtostruct();
                    copystruct(profs);
                    break;
                case '7':
                    clearstringtostruct();
                    rewritefiealdinstruct(profs);
                    break;
                case '8':
                    clearstringtostruct();
                    highestsalary(profs);
                    break;
                }
            }
            break;
        case '2':
            printdots(1);
            clearmainmenu();
            printthirdmenu();
            while(1)
            {
                k = conGetChar();
                conReset();
                if(k == 'q')
                {
                    printdots(0);
                    clearstringtostruct();
                    clearmainmenu();
                    printfirstmenu();
                    break;
                }
                switch (k)
                {
                case '1':
                    clearstringtostruct();
                    fileread("input.txt", profs);
                    break;
                case '2':
                    clearstringtostruct();
                    filewrite(profs);
                    break;
                }
            }
            break;
        }
    }

    for(i=0; i < number; i++)
    {
        if(profs[i]!= NULL){
        free( profs[i]);
      }
    }
    return 0;
}
