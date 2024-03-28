#include "mySimpleComputer.h"

int
sc_accumulatorSet (short int value)
{
  if (value <= MAX_VALUE && value >= 0)
    accumulator = value;
  else
    return -1;
  return 0;
}