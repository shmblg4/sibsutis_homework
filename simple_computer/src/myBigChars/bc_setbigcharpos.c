#include "myBigChars.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
bc_setbigcharpos (int *big, int x, int y, int value)
{
  x = bc_getbigcharpos (big, x, y, &value);
  mt_gotoXY (x, y);
  return 0;
}