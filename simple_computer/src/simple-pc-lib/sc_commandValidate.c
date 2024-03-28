#include "mySimpleComputer.h"

int
sc_commandValidate (short int command)
{
  if (((1 << 14) & command) >> 14 != FALSE)
    return -1;
  short int check = (MAX_VALUE_COMMAND << 7) & command >> 7;
  if ((check >= 0 && check <= 1) || (check >= 10 && check <= 11)
      || (check >= 20 && check <= 21) || (check >= 30 && check <= 33)
      || (check >= 40 && check <= 43) || (check >= 51 && check <= 76))
    {
      return 0;
    }
  return -1;
}