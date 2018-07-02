#include <stdio.h>

#include <pbconsole.h>

int main(void)
{
    int x = 0;
    int y = 0;

    
    
    conClear();
        conSetAttr(BG_WHITE);
for (y = 1; y < 17; y++)
    {
        for (x = 1; x < 29; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }

    
    
    
    conSetAttr(BG_GREEN);
    for (y = 13; y < 16; y++)
    {
        for (x = 12; x < 17; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
     conSetAttr(BG_BLACK);
    for (x = 6, y =11; x < 11; x++, y++) 
    {
        conMove(y, x);
        putchar(' ');
    }
    conSetAttr(BG_BLACK);
    for (y =11 ; y < 16; y++)
    {
        for (x = 11; x < 12; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    
    }

    
    conSetAttr(BG_BLACK);
    for (x = 18, y = 15; x < 23; x++, y--) 
    {
        conMove(y, x);
        putchar(' ');
    }
    conSetAttr(BG_BLACK);
    for (x = 17, y = 15; x < 21; x++, y--) 
    {
        conMove(y, x);
        putchar(' ');
    }
    conSetAttr(BG_BLACK);
    for (x = 18, y = 14; x < 21; x++, y--) 
    {
        conMove(y, x);
        putchar(' ');
    }
    
    conSetAttr(BG_BLACK);
    for (x =9 ,y = 13; x <11 ; x++, y++) 
    {
        conMove(y, x);
        putchar(' ');
}
   
     conSetAttr(BG_GREEN);
    for (x = 7, y = 10; x < 11; x++, y++) 
    {
        conMove(y, x);
        putchar(' ');
}
    for (x = 18, y = 13; x < 22; x++, y--) 
    {
        conMove(y, x);
        putchar(' ');
    }

     conSetAttr(BG_GREEN);
    for (x = 7,y = 11; x < 9; x++, y++) 
    {
        conMove(y, x);
        putchar(' ');
}
    conSetAttr(BG_BLACK);
    for (y = 11; y < 16; y++)
    {
        for (x = 17; x < 18; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 6; x < 7; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
     conSetAttr(BG_BLACK);
    for (x = 7, y = 9; x < 10; x++, y++) 
    {
        conMove(y, x);
        putchar(' ');
    }
    for (x = 18; x < 20; x++)
    {
        conMove(11, x);
        putchar(' ');
    }

    conSetAttr(BG_GREEN);
    for (x = 21; x < 22; x++)
    {
        conMove(11, x);
        putchar(' ');
    } 
    for (x = 12; x < 17; x++)
    {
        conMove(11, x);
        putchar(' ');
    }
    conSetAttr(BG_BLACK);
    for (x = 10; x < 11; x++)
    {
        conMove(11, x);
        putchar(' ');
    }
    conSetAttr(BG_BLACK);
    for (x = 13; x < 16; x++)
    {
        conMove(12, x);
        putchar(' ');}
    
    conSetAttr(BG_YELLOW);
    for (x = 10; x < 11; x++)
    {
        conMove(12, x);
        putchar(' ');
    }
    conSetAttr(BG_YELLOW);

    for (x = 16; x < 17; x++)
    {
        conMove(12, x);
        putchar(' ');
    }
    for (x = 11; x < 12; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
    for (x = 17; x < 18; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
    
    for (x = 18; x < 19; x++)
    {
        conMove(12, x);
        putchar(' ');
    } 
    for (y = 7; y < 11; y++)
    {
        for (x = 9; x < 10; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 7; y < 11; y++)
    {
        for (x = 19; x < 20; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
        for (x =10 ; x <13 ; x++)
    {
        conMove(9, x);
        putchar(' ');
    }
    for (x =16 ; x <19 ; x++)
    {
        conMove(9, x);
        putchar(' ');
    }
    for (y = 7; y < 10; y++)
    {
        for (x = 11; x < 18; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }


    conSetAttr(BG_RED);
    for (x = 9; x < 10; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
     for (y = 7; y < 10; y++)
    {
        for (x = 8; x < 9; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 13; x < 16; x++)
    {
        conMove(9, x);
        putchar(' ');
    }
    for (x = 19; x < 20; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
     for (y = 7; y < 11; y++)
    {
        for (x = 20; x < 21; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
     for (y = 6; y < 7; y++)
    {
        for (x = 12; x < 17; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 9; x < 10; x++)
    {
        conMove(6, x);
        putchar(' ');
    }
    for (x = 19; x < 20; x++)
    {
        conMove(6, x);
        putchar(' ');
    }


    conSetAttr(BG_BLACK);
    for (x = 12; x < 17; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
     for (y = 7; y < 11; y++)
    {
        for (x = 21; x < 22; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 7; y < 11; y++)
    {
        for (x = 7; x < 8; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 20, y = 10; x < 22; x++, y--) 
    {
        conMove(y, x);
        putchar(' ');
    }
    for (x = 22; x < 23; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
    for (y = 5; y < 7; y++)
    {
        for (x = 8; x < 9; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 5; y < 7; y++)
    {
        for (x = 6; x < 7; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
        for (y = 5; y < 7; y++)
    {
        for (x = 20; x < 21; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 5; y < 7; y++)
    {
        for (x = 22; x < 23; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 5; y < 6; y++)
    {
        for (x = 9; x < 20; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 7; x < 8; x++)
        {
            conMove(4, x);
            putchar(' ');
        }
    for (x = 21; x < 22; x++)
        {
            conMove(4, x);
            putchar(' ');
        }
    for (x = 8; x < 21; x++)
        {
            conMove(3, x);
            putchar(' ');
        }
    for (x = 8; x < 10; x++)
        {
            conMove(2, x);
            putchar(' ');
        }
    for (x = 8; x < 10; x++)
        {
            conMove(2, x);
            putchar(' ');
        }
    for (x = 19; x < 21; x++)
        {
            conMove(2, x);
            putchar(' ');
        }
    for (x = 9; x < 11; x++)
        {
            conMove(1, x);
            putchar(' ');
        }
    for (x = 18; x < 20; x++)
        {
            conMove(1, x);
            putchar(' ');
        }

    
    conSetAttr(BG_GREEN);
    for (y = 5; y < 7; y++)
    {
        for (x = 21; x < 22; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 5; y < 7; y++)
    {
        for (x = 7; x < 8; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 8; x <9; x++)
        {
            conMove(4, x);
            putchar(' ');
        }
    for (x = 10; x < 11; x++)
        {
            conMove(2, x);
            putchar(' ');
        }
    for (x = 11; x < 12; x++)
        {
            conMove(1, x);
            putchar(' ');
        }
    for (x = 20; x < 21; x++)
        {
            conMove(4, x);
            putchar(' ');
        }
    for (x = 18; x < 19; x++)
        {
            conMove(2, x);
            putchar(' ');
        }
    for (x = 17; x < 18; x++)
        {
            conMove(1, x);
            putchar(' ');
        }
    for (x = 10; x < 19; x++)
        {
            conMove(4, x);
            putchar(' ');
        }


    conSetAttr(BG_WHITE);
    for (x = 10; x < 11; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
    for (x = 18; x < 19; x++)
    {
        conMove(10, x);
        putchar(' ');
    }
    for (y = 6; y < 9; y++)
    {
        for (x = 10; x < 11; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (y = 6; y < 9; y++)
    {
        for (x = 18; x < 19; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    for (x = 11; x < 12; x++)
    {
        conMove(6, x);
        putchar(' ');
    }
    for (x = 17; x < 18; x++)
    {
        conMove(6, x);
        putchar(' ');
    }



    conSetAttr(BG_INTENSITY_GREEN);
        for (x = 12; x < 13; x++)
    {
        conMove(12, x);
        putchar(' ');
    }
        for (x = 10; x < 11; x++)
    {
        conMove(12, x);
        putchar(' ');
    }
    for (x = 16; x < 17; x++)
    {
        conMove(12, x);
        putchar(' ');
    }
    for (x = 18; x < 19; x++)
    {
        conMove(12, x);
        putchar(' ');
    }  
        for (x = 9; x < 10; x++)
        {
            conMove(4, x);
            putchar(' ');
        }
    for (x = 19; x < 20; x++)
        {
            conMove(4, x);
            putchar(' ');
        }
    for (x = 11; x < 18; x++)
        {
            conMove(2, x);
            putchar(' ');
        }
    for (x = 12; x < 17; x++)
        {
            conMove(1, x);
            putchar(' ');
        }

    conSetAttr(BG_BLACK);
    for (x = 12 ; x < 17; x++) 
    {
        conMove(16,x);
        putchar(' ');
    }
    
    
    conReset();
    puts("");
    return 0;
}

