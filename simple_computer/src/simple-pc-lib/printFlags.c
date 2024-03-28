#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printFlags (void)
{
  char flags[] = { 'O', 'D', 'M', 'R', 'P' };
  short int flag_values[] = { 0b1, 0b10, 0b100, 0b1000, 0b10000 };
  for (int i = 0; i < 5; ++i)
    {
      short int tmp = (1 << i) & flag_register;
      mt_gotoXY (2, 90 + 3 * i);
      if (tmp == flag_values[i])
        {
          char tmp[3] = { ' ' };
          tmp[0] = flags[i];
          write (STDOUT_FILENO, tmp, strlen (tmp));
        }
      else
        write (STDOUT_FILENO, "_  ", strlen ("_  "));
    }
  mt_gotoXY (26, 0);
}