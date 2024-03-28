#include "mySimpleComputer.h"

int
sc_icounterSet (short int value)
{
  if (value <= MAX_VALUE && value >= 0)
    command_counter = value;
  else
    return -1;
  return 0;
}