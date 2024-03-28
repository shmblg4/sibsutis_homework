#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void
printCommand (void)
{
  short int command;
  short int operand;
  short int sign;
  sc_commandDecode (memory[command_counter], &sign, &command, &operand);
  char line[20];
  sprintf (line, "+ gt%X : %X", command, operand);

  mt_gotoXY (5, 94);
  write (STDOUT_FILENO, line, strlen (line));
  mt_gotoXY (26, 0);
}