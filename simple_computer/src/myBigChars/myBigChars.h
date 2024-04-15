#ifndef MYBIGCHARS_H
#define MYBIGCHARS_H
#pragma once

#define START 10
#define FONT_PATH "./bin/font.bin"

enum colors;

void bc_genfont ();
int bc_strlen (char *str);
void bc_readbc (int *sym, int n);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);
int bc_printbigchar (int sym[2], int x, int y, enum colors fg, enum colors bg);
void printBigCell (void);
#endif