#include "myTerm.h"
#include <unistd.h>

int
mt_setcursorvisible (int value)
{
  if (value > 1 || value < 0)
    return -1;
  switch (value)
    {
    case 1:
      write (STDOUT_FILENO, "\e[?25h", 6);
      break;
    case 0:
      write (STDOUT_FILENO, "\e[?25l", 6);
    default:
      break;
    }
  return -1;
}