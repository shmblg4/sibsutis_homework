#include "myBigChars.h"
#include <stdio.h>

void
bc_genfont ()
{
  FILE *file = fopen (FONT_PATH, "wb");
  char symbols[] = {
    0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x78, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x7E, 0x3C, 0x66, 0x6,  0xC,  0x18, 0x30, 0x60, 0x7E,
    0x3C, 0x66, 0x6,  0x1C, 0x1C, 0x6,  0x66, 0x3C, 0x66, 0x66, 0x66, 0x66,
    0x7E, 0x7E, 0x6,  0x6,  0x7E, 0x60, 0x60, 0x7C, 0x6,  0x6,  0x66, 0x3C,
    0x1E, 0x30, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x3C, 0x7E, 0x6,  0xC,  0x18,
    0x30, 0x30, 0x30, 0x30, 0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x66, 0x3C,
    0x3C, 0x66, 0x66, 0x66, 0x3E, 0x6,  0xC,  0x78, 0x3C, 0x66, 0x66, 0x66,
    0x66, 0x7E, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x66, 0x7C,
    0x3C, 0x66, 0x60, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x7C, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x7C, 0x7E, 0x60, 0x60, 0x7E, 0x7E, 0x60, 0x60, 0x7E,
    0x7E, 0x60, 0x60, 0x7E, 0x60, 0x60, 0x60, 0x60, 0x0,  0x18, 0x18, 0x7E,
    0x7E, 0x18, 0x18, 0x0,  0x0,  0x0,  0x0,  0x7E, 0x7E, 0x0,  0x0,  0x0,

  };
  for (int i = 0; i < sizeof (symbols) / sizeof (char); i++)
    {
      fwrite (&symbols[i], sizeof (char), 1, file);
    }
  fclose (file);
}
