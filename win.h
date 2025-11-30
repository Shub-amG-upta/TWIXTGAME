#ifndef WIN_H
#define WIN_H
#include"game.h"
#include"instructions.h"
#include"colour.h"

int checklinkwin(board*b,int x1,int y1,int x2,int y2,status p);
int checkgrid(board*b,int x,int y,status p);
int checkwin(board *b,status p);

#endif
