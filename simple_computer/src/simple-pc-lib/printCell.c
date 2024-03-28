#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printCell (int address)
{
  mt_gotoXY (((address / 10) + 2), ((address % 10 * 6) + 2));
  write (STDOUT_FILENO, "+", strlen ("+"));
  for (int i = 3; i >= 0; i--)
    {
      int tmp = (0b1111 << i * 4 & memory[address]) >> i * 4;
      char temp[2] = { 0 };
      snprintf (temp, 2, "%01X", tmp);
      write (STDOUT_FILENO, temp, strlen (temp));
    }
  mt_gotoXY (26, 0);
}