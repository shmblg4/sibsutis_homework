#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printTerm (int address, int input)
{
  static int stroka = 19;
  mt_gotoXY (stroka, 68);
  char temp[5] = { 0 };
  snprintf (temp, 5, "%02d", address);
  write (STDOUT_FILENO, temp, strlen (temp));
  if (input)
    {
      write (STDOUT_FILENO, ">", strlen (">"));
    }
  else
    {
      mt_gotoXY (stroka, 72);
      write (STDOUT_FILENO, "+", strlen ("+"));
      char tmp[5] = { 0 };
      snprintf (tmp, 5, "%04X", memory[address]);
      write (STDOUT_FILENO, tmp, strlen (tmp));
    }
  stroka++;
  mt_gotoXY (26, 0);
}