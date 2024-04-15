#include "myBigChars.h"

int
bc_strlen (char *str)
{
  int res = 0;
  int i = 0;
  while (*(str + i) != '\0')
    {
      if ((*(str + i) & 0xFF) == 0xD1 || (*(str + i) & 0xFF) == 0xD0)
        {
          i++;
          continue;
        }
      i++;
      res++;
    }

  return res;
}