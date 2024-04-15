#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>
#include <unistd.h>

void
printBigCell (void)
{
  int sym[2];
  short value;
  short command;
  short sign;
  short operand;
  sc_memoryGet (0, &value);
  sc_commandDecode (value, &sign, &command, &operand);
  if (sign == 1)
    {
      bc_readbc (&sym[0], 16);
      bc_printbigchar (sym, 63, 9, 0, 0);
    }
  else
    {
      bc_readbc (&sym[0], 17);
      bc_printbigchar (sym, 63, 9, 0, 0);
    }
  int sym_i, sym_j;
  sym_i = ((0xF << 4) & command) >> 4;
  sym_j = 0xF & command;
  bc_readbc (&sym[0], sym_i);
  bc_printbigchar (sym, 72, 9, 0, 0);
  bc_readbc (&sym[0], sym_j);
  bc_printbigchar (sym, 81, 9, 0, 0);
  sym_i = ((0xF << 4) & operand) >> 4;
  sym_j = 0xF & operand;
  bc_readbc (&sym[0], sym_i);
  bc_printbigchar (sym, 90, 9, 0, 0);
  bc_readbc (&sym[0], sym_j);
  bc_printbigchar (sym, 99, 9, 0, 0);
  mt_gotoXY (0, 30);
}
//
// 63 9
