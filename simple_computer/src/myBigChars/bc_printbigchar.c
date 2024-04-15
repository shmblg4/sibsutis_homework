#include "myBigChars.h"
#include "myTerm.h"
#include <stdio.h>
#include <unistd.h>

int
bc_printbigchar (int sym[2], int x, int y, enum colors fg, enum colors bg)
{
  for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 4; j++, y++)
        {
          mt_gotoXY (x, y);
          unsigned char buf = ((0xff << 8 * j) & sym[i]) >> 8 * j;
          for (int k = 7; k >= 0; k--)
            {
              if (((1 << k) & buf) > 0)
                write (STDOUT_FILENO, "▓", sizeof ("▓"));
              else
                write (STDOUT_FILENO, " ", sizeof ("1"));
            }
        }
    }
  return 0;
}
