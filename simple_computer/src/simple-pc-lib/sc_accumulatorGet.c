#include "mySimpleComputer.h"

int
sc_accumulatorGet (short int *value)
{
  if (!value)
    {
      return -1;
    }
  *value = accumulator;
  return 0;
}