#ifndef GAME_H
#define GAME_H

// #define BOARDSIZE 26

typedef enum status{
    empty=0,
    red=1,
    black=2,
}status;

typedef struct link {
int x1,y1;  
int x2,y2;  
status curr;   
struct link *next;
}link;

typedef struct {
status pin;  
}Cell;

typedef struct {
    Cell **cells;
    link *links; 
    int redcount;
    int blackcount;
    status curr;
    int size;
} board;

void addlink(board*b,int x1,int y1,int x2,int y2,status buff);
int checklink(board*b,int x1,int y1,int x2,int y2);
void makeboard(board *b, int size);
void freeboard(board *b);
void resetboard(board *b);
int addpin(board *b, int x, int y);
void switchplayer(board *b);
void printboard(board *b);
void restartgame(board *b);
void quitgame();
int crosslink(board *b,int x1,int y1,int x2,int y2);
void linkgeneration(board*b,int x,int y);









#endif