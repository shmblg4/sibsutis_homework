#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printCounters (void)
{
  mt_gotoXY (63, 5);
  write (STDOUT_FILENO, "T: 00", strlen ("T: 00"));
  mt_gotoXY (73, 5);
  write (STDOUT_FILENO, "IC: +", strlen ("IC: +"));
  for (int i = 3; i >= 0; i--)
    {
      short int tmp = (0b1111 << i * 4 & command_counter) >> i * 4;
      char temp[2] = { 0 };
      snprintf (temp, 2, "%01X", tmp);
      write (STDOUT_FILENO, temp, strlen (temp));
    }
  mt_gotoXY (0, 26);
}