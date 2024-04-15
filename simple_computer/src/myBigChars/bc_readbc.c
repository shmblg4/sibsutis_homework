#include "myBigChars.h"
#include <stdio.h>

void
bc_readbc (int *sym, int n)
{
  FILE *file = fopen (FONT_PATH, "rb");
  fseek (file, 8 * n, SEEK_SET);
  fread (sym, sizeof (int), 2, file);
}