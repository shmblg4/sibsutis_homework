#include "mySimpleComputer.h"
#include <stdio.h>

int
sc_memoryLoad (char *filename)
{
  if (!filename)
    return -1;
  FILE *file = fopen (filename, "rb");
  if (!file)
    return -1;
  fread (memory, sizeof (short int), RAM_SIZE, file);
  fclose (file);
  return 0;
}