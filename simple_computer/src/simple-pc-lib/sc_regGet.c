#include "mySimpleComputer.h"

int
sc_regGet (short int reg, short int *value)
{
  if (!value)
    return -1;
  *value = flag_register;
  return 0;
}