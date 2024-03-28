#include "mySimpleComputer.h"
#include <stdlib.h>

int
sc_regSet (short int reg, short int value)
{
  if (reg >= 5)
    return -1;
  if (value > TRUE || value < FALSE)
    return -1;

  if (value == TRUE)
    flag_register = flag_register | (1 << reg);
  else
    flag_register = flag_register & ~(1 << reg);

  return 0;
}