#include "mySimpleComputer.h"
#include <stdio.h>

int
sc_memorySet (short int address, short int value)
{
  if ((address < RAM_SIZE) && (address >= 0) && (value <= MAX_VALUE)
      && (value >= 0))
    memory[address] = value;
  else
    return -1;
  return 0;
}