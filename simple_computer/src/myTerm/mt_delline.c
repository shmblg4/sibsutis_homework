#include "myTerm.h"
#include <unistd.h>

int
mt_delline (void)
{
  write (STDOUT_FILENO, "\e[2K\r", 5);
  return 0;
}
