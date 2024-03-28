#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printAccumulator (void)
{
  mt_gotoXY (2, 64);
  write (STDOUT_FILENO, "sc: +", strlen ("sc: +"));
  for (int i = 3; i >= 0; i--)
    {
      short int tmp = (0b1111 << i * 4 & command_counter) >> i * 4;
      // printf ("%X", tmp);
      char temp[2] = { 0 };
      snprintf (temp, 2, "%01X", tmp);
      write (STDOUT_FILENO, temp, strlen (temp));
    }
  write (STDOUT_FILENO, " hex: ", strlen (" hex: "));
  for (int i = 3; i >= 0; i--)
    {
      short int tmp = (0b1111 << i * 4 & command_counter) >> i * 4;
      char temp[2] = { 0 };
      snprintf (temp, 2, "%01X", tmp);
      write (STDOUT_FILENO, temp, strlen (temp));
    }
  printf (" ");
  mt_gotoXY (26, 0);
}