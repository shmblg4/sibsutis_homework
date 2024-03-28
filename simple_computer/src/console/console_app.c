#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

short int memory[RAM_SIZE];
short int accumulator;
short int flag_register;
short int command_counter;

int
main ()
{

  if (!isatty (fileno (stdout)))
    return 1;
  int rows, cols;
  mt_getscreensize (&rows, &cols);
  if (rows < 26 && cols < 108)
    return 1;

  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();

  mt_clrscr ();

  for (int i = 0; i < 25; i++)
    {
      for (int j = 0; j < 108; j++)
        {
          write (STDOUT_FILENO, "*", strlen ("*"));
        }
      write (STDOUT_FILENO, "\n", strlen ("\n"));
    }

  for (int i = 0; i < 20; i++)
    {
      sc_memorySet (i, MAX_VALUE - i);
    }

  for (int i = 0; i < RAM_SIZE; i++)
    printCell (i);

  sc_regSet (R, TRUE);
  printFlags ();

  printDecodedCommand (6708);

  printAccumulator ();

  printCounters ();

  printTerm (11, 0);
  printTerm (12, 0);
  printTerm (13, 0);
  printTerm (14, 0);
  printTerm (15, 0);

  return 0;
}