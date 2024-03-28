#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
mt_setbgcolor (enum colors color)
{
  char command[20];
  sprintf (command, "\e[47;%dm", color);
  write (STDOUT_FILENO, command, strlen (command));
  return 0;
}