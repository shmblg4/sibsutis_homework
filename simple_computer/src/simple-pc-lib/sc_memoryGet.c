#include "mySimpleComputer.h"

int
sc_memoryGet (short int address, short int *value)
{
  if (address >= RAM_SIZE || address < 0 || !value)
    {
      return -1;
    }
  *value = memory[address];
  return 0;
}