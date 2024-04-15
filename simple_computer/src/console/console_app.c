#include "myBigChars.h"
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

  // for (int i = 0; i < 25; i++)
  //   {
  //     for (int j = 0; j < 108; j++)
  //       {
  //         write (STDOUT_FILENO, "*", strlen ("*"));
  //       }
  //     write (STDOUT_FILENO, "\n", strlen ("\n"));
  //   }

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

  bc_box (0, 0, 61, 15, 0, 0, " Оперативная память ", 0, 0);
  bc_box (62, 0, 23, 3, 0, 0, " Аккумулятор ", 0, 0);
  bc_box (85, 0, 24, 3, 0, 0, " Регистр  флагов ", 0, 0);
  bc_box (62, 4, 23, 2, 0, 0, " Счетчик  комманд ", 0, 0);

  bc_box (85, 4, 24, 2, 0, 0, " Команда ", 0, 0);
  bc_box (62, 7, 47, 11, 0, 0, " Редактируемая ячейка (увеличено) ", 0, 0);
  bc_box (0, 16, 61, 2, 0, 0, " Редактируемая ячейка (формат) ", 0, 0);
  bc_box (0, 19, 66, 7, 0, 0, " Кеш процессора ", 0, 0);

  bc_box (67, 19, 11, 7, 0, 0, " IN--OUT ", 0, 0);
  bc_box (78, 19, 31, 7, 0, 0, " Клавиши ", 0, 0);
  bc_genfont ();
  printBigCell ();
  return 0;
}