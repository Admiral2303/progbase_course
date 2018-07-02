#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>

int main(void)
{
    /* colors encoding table */
    const unsigned long MILLIS = 10;

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
    char colorsPalette[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
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
    int colorsPaletteLength = sizeof(colorsPalette) / sizeof(colorsPalette[0]);
    int imageLength = (sizeof(image) / sizeof(image[0])) - 1 ;
    int i = 0;
    int j = 0;
    int colorPairIndex = 0;
    int temp = 0;
    char colorCode = '\0';
    char color = '\0';
    conClear();
    for (i = 0; i < colorsPaletteLength; i++)
    {
        char colorCode = '\0';
        char color = '\0';
        colorCode = colorsPalette[i];
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
        conSetAttr(color);
        conMove(1, i + 1);
        putchar(' ');
        conReset();

    }
    puts(" ");
    conReset();

    /*******************************************************************************************************************************/
    for(i = 0; i <= imageLength; i ++)
    {
        for( j = 0; j <= imageLength; j ++)
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
            conSetAttr(color);
            conMove(i + 1, j + 19);
            putchar(' ');
        }
        conReset();
        puts("");
    }
    puts("");
    conReset();

    /************************************************************************************************************************************/

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

    /**************************************************************************************************************************/
    for(i = 0; i <= imageLength; i++)
    {
        for( j =0; j <= 13; j++)
        {
            temp=image[i][j];
            image[i][j] = image [i][27-j];
            image[i][27-j]=temp;
        }
    }

    for(i = 0; i <= imageLength; i++)
    {
        for( j =0; j <= imageLength; j++)
        {
            char colorCode = '\0';
            char color = '\0';
            colorCode = image[i][j];
            for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];
                if (colorCode == colorPairCode)
                {
                    color = colorPairColor;
                    break;  /* we have found our color, break the loop */
                }
            }
            conSetAttr(color);
            fflush(stdout);
            sleepMillis(MILLIS);
            conMove(i+1 ,j + 79);
            putchar(' ');
        }
        conReset();
    }
    puts("");

    conReset();

    return 0;
}
