#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printDecodedCommand (short int value)
{
  mt_gotoXY (2, 17);
  char buffer[10] = { 0 };
  sprintf (buffer, "%05d", value);
  write (STDOUT_FILENO, "dec: ", strlen ("dec: "));
  write (STDOUT_FILENO, buffer, strlen (buffer));
  write (STDOUT_FILENO, " | ", strlen (" | "));
  snprintf (buffer, 6, "%05o", value);
  write (STDOUT_FILENO, "oct: ", strlen ("oct: "));
  write (STDOUT_FILENO, buffer, strlen (buffer));
  write (STDOUT_FILENO, " | ", strlen (" | "));
  snprintf (buffer, 6, "%04X", value);
  write (STDOUT_FILENO, "hex: ", strlen ("hex: "));
  write (STDOUT_FILENO, buffer, strlen (buffer));
  printBinary (value);
  mt_gotoXY (0, 26);
}