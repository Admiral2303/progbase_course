#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pbconsole.h>
#include <time.h>
#include <progbase.h>
#include "function.h"


void cat(){

conClear();
 const unsigned long MILLIS = 5;
     const char colorsTable[16][2] =
     {
         {'0', BG_BLACK},
         {'1', BG_INTENSITY_BLACK},
         {'2', BG_RED },
         {'3', BG_INTENSITY_RED},
         {'4', BG_GREEN},
         {'5', BG_INTENSITY_GREEN},
         {'6', BG_YELLOW},
         {'7', BG_INTENSITY_YELLOW},
         {'8', BG_BLUE},
         {'9', BG_INTENSITY_BLUE},
         {'A', BG_MAGENTA},
         {'B', BG_INTENSITY_MAGENTA},
         {'C', BG_CYAN},
         {'D', BG_INTENSITY_CYAN},
         {'E', BG_WHITE},
         {'F', BG_INTENSITY_WHITE}
     };
     int colorsTableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);

     char image[28][28] =
     {
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { 'F','F','F','F','F','F','F','F','F','F','0','0','0','0','0','0','0','0','0','0','0','F','F','F','F','F','F','F' },
         { 'F','F','F','F','F','F','F','F','0','0','F','F','F','F','F','F','F','F','F','F','0','0','0','0','F','F','F','F' },
         { 'F','F','F','F','F','0','0','0','F','F','F','F','F','F','F','0','F','F','F','F','F','F','F','0','0','0','0','F' },
         { 'F','F','F','0','0','F','F','F','F','F','F','F','F','F','F','0','F','F','F','F','F','F','F','F','F','F','0','0' },
         { 'F','0','0','F','F','F','F','F','F','0','F','F','F','F','F','0','F','F','F','F','F','F','F','F','F','F','F','F' },
         { '0','F','F','F','F','F','F','F','0','F','0','C','F','F','F','F','0','F','F','0','F','F','F','F','F','F','F','F' },
         { 'F','0','0','F','F','F','F','F','0','0','0','C','0','F','F','F','0','F','F','0','F','F','F','F','F','F','F','F' },
         { 'F','F','F','0','F','F','F','F','0','0','C','C','F','0','F','F','F','0','F','F','0','F','F','F','F','F','F','F' },
         { 'F','F','F','F','0','F','F','F','F','0','C','C','F','0','F','F','F','0','F','F','0','F','F','F','F','F','F','F' },
         { 'F','F','F','F','0','F','F','F','F','F','C','C','0','3','0','F','F','F','0','F','F','0','F','F','F','F','F','F' },
         { 'F','F','F','0','F','F','F','F','F','0','F','C','F','0','F','F','F','F','0','0','0','0','F','F','F','F','F','F' },
         { 'F','0','0','F','F','F','F','F','0','F','0','C','F','0','F','F','F','F','F','F','F','F','F','F','F','F','F','F' },
         { '0','F','F','F','F','F','F','F','0','0','0','C','0','F','F','F','F','F','0','0','0','0','0','0','0','0','0','0' },
         { 'F','0','0','F','F','F','F','F','C','C','C','C','F','F','F','F','F','F','F','F','F','F','F','F','0','0','F','F' },
         { 'F','F','F','0','0','0','0','0','C','C','C','C','0','0','0','0','0','0','0','0','0','0','0','0','0','F','F','F' },
         { 'F','F','F','F','F','C','C','C','C','C','C','C','C','C','C','F','F','F','F','F','F','F','F','F','F','F','F','F' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
         { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' }
     };

     int imageLength = (sizeof(image) / sizeof(image[0])) - 1 ;
     int i = 0;
     int j = 0;
     int colorPairIndex = 0;
     char colorCode = '\0';
     char color = '\0';


     /*******************************************************************************************************************************/
     for(j = imageLength; j >=0; j--)
    {
        if(j % 2 ==1 )
        {
            for(i=0; i<=imageLength; i++)
            {
                colorCode = image[i][j];
                for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
                {
                    char colorPairCode = colorsTable[colorPairIndex][0];
                    char colorPairColor = colorsTable[colorPairIndex][1];
                    if (colorCode == colorPairCode)
                    {
                        color = colorPairColor;
                        break;
                    }
                }
                conMove(i + 1,j + 49);
                conSetAttr(color);
                fflush(stdout);
                sleepMillis(MILLIS);
                putchar(' ');
            }
        }

        if(j % 2 ==0 )
        {
            for(i = imageLength; i>=0; i--)
            {
                colorCode = image[i][j];
                for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
                {
                    char colorPairCode = colorsTable[colorPairIndex][0];
                    char colorPairColor = colorsTable[colorPairIndex][1];
                    if (colorCode == colorPairCode)
                    {
                        color = colorPairColor;
                        break;
                    }
                }
                conMove(i + 1,j + 49);
                conSetAttr(color);
                fflush(stdout);
                sleepMillis(MILLIS);

                putchar(' ');
            }
        }
    }
    conReset();
    puts("");
}
