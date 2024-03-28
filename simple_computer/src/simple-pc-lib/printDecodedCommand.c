#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printDecodedCommand (short int value)
{
  mt_gotoXY (17, 2);
  char tmp[6] = { 0 };
  snprintf (tmp, 6, "%05d", value);
  write (STDOUT_FILENO, "dec: ", strlen ("dec: "));
  write (STDOUT_FILENO, tmp, strlen (tmp));
  write (STDOUT_FILENO, " | ", strlen (" | "));
  snprintf (tmp, 6, "%05o", value);
  write (STDOUT_FILENO, "oct: ", strlen ("oct: "));
  write (STDOUT_FILENO, tmp, strlen (tmp));
  write (STDOUT_FILENO, " | ", strlen (" | "));
  snprintf (tmp, 6, "%04X", value);
  write (STDOUT_FILENO, "hex: ", strlen ("hex: "));
  write (STDOUT_FILENO, tmp, strlen (tmp));
  // mt_gotoXY (17, 41);
  printBinary (value);
  mt_gotoXY (26, 0);
}