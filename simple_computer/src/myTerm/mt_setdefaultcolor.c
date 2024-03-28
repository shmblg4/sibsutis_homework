#include "myTerm.h"
#include <unistd.h>

int
mt_setdefaultcolor (void)
{
  write (STDOUT_FILENO, "\e[m", 3);
  return 0;
}