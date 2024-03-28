#include "mySimpleComputer.h"
#include <stdio.h>

short int memory[RAM_SIZE];
short int accumulator;
short int flag_register;
short int command_counter;

int
main ()
{
  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  for (int i = 0; i < 20; i++)
    {
      sc_memorySet (i, MAX_VALUE);
    }
  short int counter = 0;
  for (int i = 0; i < RAM_SIZE; i++)
    {
      printCell (i);
      counter++;
      if (counter == 10)
        {
          printf ("\n");
          counter = 0;
        }
    }
  printf ("\n");
  printf ("sc_memorySet(0, MAX_VALUE + 1) = %d\n",
          sc_memorySet (0, MAX_VALUE + 1));
  printf ("sc_regSet (O, TRUE) = %d\n", sc_regSet (O, TRUE));
  printf ("sc_regSet (D, TRUE) = %d\n", sc_regSet (D, TRUE));
  printf ("sc_regSet (M, FALSE) = %d\n", sc_regSet (M, FALSE));
  printf ("sc_regSet (R, TRUE) = %d\n", sc_regSet (R, TRUE));
  printf ("sc_regSet (P, FALSE) = %d\n", sc_regSet (P, FALSE));
  printFlags ();
  printf ("\n");
  printf ("sc_regSet (P, 10) = %d\n", sc_regSet (P, 10));
  printFlags ();
  printf ("\n");
  printf ("sc_accumulatorSet(100) = %d\n", sc_accumulatorSet (100));
  printf ("sc_accumulatorSet(MAX_VALUE + 1) = %d\n",
          sc_accumulatorSet (MAX_VALUE + 1));
  printf ("sc_icounterSet(0x000E) = %d\n", sc_icounterSet (0x000E));
  printf ("sc_icounterSet(MAX_VALUE + 1) = %d\n",
          sc_icounterSet (MAX_VALUE + 1));
  printCounters ();
  printf ("\n");
  printDecodedCommand (memory[1]);
  printf ("\n");
  printAccumulator ();
  printf ("\n");
  short int command = 0;
  sc_commandEncode (0, 10, 10, &command);
  printDecodedCommand (command);
  printf ("\n");
  return 0;
}