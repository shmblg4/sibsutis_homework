#include "myTerm.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int
mt_getscreensize (int *rows, int *cols)
{
  if (!rows || !cols)
    return -1;

  struct winsize size;

  if (ioctl (STDOUT_FILENO, TIOCGWINSZ, &size) == -1)
    return -1;

  *rows = size.ws_row;
  *cols = size.ws_col;
  return 0;
}