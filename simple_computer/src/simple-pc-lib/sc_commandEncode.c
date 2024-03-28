#include "mySimpleComputer.h"

int
sc_commandEncode (short int sign, short int command, short int operand,
                  short int *value)
{
  if (!value)
    return -1;
  if (sign < 0 || sign > 1)
    return -1;
  if (command > MAX_VALUE_COMMAND || command < MIN_VALUE_COMMAND)
    return -1;
  if (operand > MAX_VALUE_COMMAND || operand < MIN_VALUE_COMMAND)
    return -1;
  *value = *value | (MAX_VALUE_COMMAND & operand);
  *value = *value | ((MAX_VALUE_COMMAND << 7) & command);
  *value = *value | ((MAX_VALUE_COMMAND << 14) & operand);
  return 0;
}