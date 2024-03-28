#include "myTerm.h"
#include <unistd.h>

int
mt_clrscr (void)
{
  write (STDOUT_FILENO, "\ec", 2);
  return 0;
}
