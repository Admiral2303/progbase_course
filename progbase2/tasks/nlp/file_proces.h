#ifndef FILE_PROCES_H
#define FILE_PROCES_H
#include <stdio.h>
#include "list.h"



Text * File_readFile(Text * self, const char * fileName);
void File_printResult(Text * self, const char * writeFileName, int count);


#endif