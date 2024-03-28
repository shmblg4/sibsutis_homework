#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printBinary (int num)
{
  mt_gotoXY (17, 41);
  write (STDOUT_FILENO, "bin: ", strlen ("bin: "));

  for (int i = 14; i >= 0; i--)
    {
      short int tmp = (1 << i) & num;
      if (tmp > 0)
        write (STDOUT_FILENO, "1", strlen ("1"));
      else
        write (STDOUT_FILENO, "0", strlen ("0"));
    }
}