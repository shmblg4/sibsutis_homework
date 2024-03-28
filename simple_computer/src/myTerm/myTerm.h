#ifndef MYTERM_H
#define MYTERM_H

enum colors
{
  BLACK = 30,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  PURPLE,
  LIGHT_BLUE,
  GREY,
};

int mt_clrscr (void);
int mt_gotoXY (int x, int y);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors);
int mt_setbgcolor (enum colors);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);

#endif