#include "mySimpleComputer.h"

int
sc_commandDecode (short int value, short int *sign, short int *command,
                  short int *operand)
{
  if (value > MAX_VALUE)
    return -1;
  if (((1 << 14) & value) != COMMAND_CODE)
    return -1;
  *operand = MAX_VALUE_COMMAND & value;
  *command = ((MAX_VALUE_COMMAND << 7) & value) >> 7;
  *sign = ((1 << 14) & value) >> 14;
  return 0;
}