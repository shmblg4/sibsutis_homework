#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
mt_gotoXY (int x, int y)
{
  char command[20];
  sprintf (command, "\e[%d;%dH", x, y);
  write (STDOUT_FILENO, command, strlen (command));
  return 0;
}