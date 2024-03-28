#include "mySimpleComputer.h"
#include <stdio.h>

int
sc_memorySave (char *filename)
{
  if (!filename)
    return -1;

  FILE *file = fopen (filename, "wb");
  if (!file)
    return -1;
  fwrite (memory, sizeof (short int), RAM_SIZE, file);
  fclose (file);
  return 0;
}