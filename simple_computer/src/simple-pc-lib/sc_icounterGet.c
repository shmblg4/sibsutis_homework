#include "mySimpleComputer.h"

int
sc_icounterGet (short int *value)
{
  if (!value)
    {
      return -1;
    }
  *value = command_counter;
  return 0;
}