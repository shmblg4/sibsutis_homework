#include <myBigChars.h>
#include <myTerm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  static int stolbec = START;
  if (stolbec != START)
    stolbec += 8;
  return stolbec;
}