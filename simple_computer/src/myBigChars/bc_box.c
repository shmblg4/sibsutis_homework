#include "myBigChars.h"
#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  mt_setfgcolor (box_fg);
  mt_setbgcolor (box_bg);

  mt_gotoXY (x1, y1);
  write (STDOUT_FILENO, "┌", strlen ("┌"));
  for (int i = 0; i < x2 - 2; ++i)
    {
      write (STDOUT_FILENO, "─", strlen ("─"));
    }
  write (STDOUT_FILENO, "┐", strlen ("┐"));

  for (int i = 1; i < y2; i++)
    {
      mt_gotoXY (x1, y1 + i + (y1 != 0 ? 0 : 1));
      write (STDIN_FILENO, "│", strlen ("│"));
      mt_gotoXY (x1 + x2 - (x1 != 0 ? 1 : 0), y1 + i + (y1 != 0 ? 0 : 1));
      write (STDIN_FILENO, "│", strlen ("│"));
    }

  mt_gotoXY (x1, y1 + y2);
  write (STDOUT_FILENO, "└", strlen ("└"));

  for (int i = 0; i < x2 - 2; ++i)
    {
      write (STDOUT_FILENO, "─", strlen ("─"));
    }
  write (STDOUT_FILENO, "┘", strlen ("┘"));

  mt_setdefaultcolor ();

  if (header)
    {
      mt_setfgcolor (header_fg);
      mt_setbgcolor (header_bg);

      mt_gotoXY (x1
                     + ((x2 / 2)
                        - (strlen (header) > 9 ? (strlen (header) / 2 - 1) / 2
                                               : strlen (header) / 2)),
                 y1);
      write (STDOUT_FILENO, header, strlen (header));
      mt_setdefaultcolor ();
    }

  mt_gotoXY (30, 30);

  return 0;
}