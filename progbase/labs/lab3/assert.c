#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#include "assert.h"


void validtesting()
{
    assert(validtest("11") == 0);
    assert(validtest("1a1") == 1);
    assert(validtest(" ") == 1);
    assert(validtest(".") == 1);
    assert(validtest("<^-^>") == 1);
}




void validtestfloatin()
{
    assert(validtestfloat("sss") == 1);
    assert(validtestfloat("2.3") == 0);
    assert(validtestfloat(" ") == 1);
    assert(validtestfloat("sssss2.3sss") == 1);

}


void check()
{
    int size = 3;
    struct profecional * prof[size];
    for (int i = 0; i < size; i++)
    {
        prof[i] = malloc(sizeof(struct profecional));
    }
    strcpy(prof[1]->profname, "cccc");
    prof[1]->salary = 1000;
    assert(checksalary(prof,1,1001) == 1);
    assert(checksalary(prof,1,1) == 0);
    for (int i = 0; i < size; i++)
    {
        free(prof[i]);
    }
}


void filetest()
{
    assert(filecheck("input.txt") == 0);
    assert(filecheck("1244444") == 1);
}


void validdel1()
{
    assert(scanint("isss") == -1);
    assert(scanint("55") == 55);
    assert(scanint("<-<") == -1);
    assert(scanint("dd4") == -1);
}

//int deltstruct1(struct profecional * profs[],int i);


void checkdelete()
{
    int size = 3;
    struct profecional * prof[size];
    for (int i = 0; i < size; i++)
    {
        prof[i] = malloc(sizeof(struct profecional));
    }
    prof[0] = NULL;
    assert(deltstruct1(prof,2) == 0);
    assert(deltstruct1(prof,0) == 1);
    for (int i = 0; i < size; i++)
    {
        free(prof[i]);
    }
}

void checkstruct2()
{
    int size = 4;
    struct profecional * prof[size];
    for (int i = 0; i < size; i++)
    {
        prof[i] = malloc(sizeof(struct profecional));
    }
    prof[0] = NULL;
    assert(checkstruct(prof,2) == 0);
    assert(checkstruct(prof,0) == 1);
    for (int i = 0; i < size; i++)
    {
        free(prof[i]);
    }
}

//int copstr(struct profecional * profs[],int i ,int k);
void checkcopy()
{
    int size = 3;
    struct profecional * prof[size];
    for (int i = 0; i < size; i++)
    {
        prof[i] = malloc(sizeof(struct profecional));
    }
    prof[0] = NULL;
    prof[1]->salary = 1000;
    prof[1]->score = 2.5;
    prof[1]->information.year = 2012;
    prof[2]->salary = 5698;
    prof[2]->score = 8.6;
    prof[2]->information.year = 2010;
    assert(copstr(prof,1,2)->salary == 1000);
    assert(copstr(prof,1,2)->score == 2.5);
    assert(copstr(prof,1,2)->information.year == 2012);
    assert(copstr(prof,0,2) == NULL);
    assert(copstr(prof,0,2) == NULL);
    for (int i = 0; i < size; i++)
    {
        free(prof[i]);
    }
}
