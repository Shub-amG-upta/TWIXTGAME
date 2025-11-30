#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"colour.h"
#include"game.h"
#include"instructions.h"

int grid[110][110];

// for(int i=0;i<110;i++){
// for(int j=0;j<110;j++) grid[i][j]=0;
// }

int varx[]={2,1,1,-2,-2,2,-1,-1};
int vary[]={1,2,-2,1,-1,-1,-2,2};

int checklinkwin(board*b,int x1,int y1,int x2,int y2,status p){
link*l=b->links;
while(l!=NULL){
if(l->curr==p){
if ((l->x1==x1 && l->y1==y1 && l->x2==x2&& l->y2==y2) ||(l->x1==x2 && l->y1==y2 &&l->x2==x1 && l->y2==y1)) return 1;
}
l=l->next;
}
return 0;
}

int checkgrid(board*b,int x,int y,status p){
grid[x][y]=1;
for(int i=0;i<8;i++){
int buffx=x+varx[i];
int buffy=y+vary[i];
if(buffx<0||buffx>=b->size||buffy<0||buffy>=b->size) continue;
if(b->cells[buffx][buffy].pin!=p) continue;
if(checklinkwin(b,x,y,buffx,buffy,p)==0) continue;
if(grid[buffx][buffy]==0) checkgrid(b,buffx,buffy,p);
}
return 0;
}

int checkwin(board*b,status p){
for(int i=0;i<b->size;i++){
for(int j=0;j<b->size;j++) grid[i][j]=0;
}


for(int i=2;i<b->size-2;i++){
int x=-1,y=-1;

if(p==red){ x=2;
y=i;
}
else{y=2;
x=i;
}

if(b->cells[x][y].pin==p){
checkgrid(b,x,y,p);
}
}

for(int i=2;i<b->size-2;i++){
int x=-1,y=-1;

if(p==red){ x=b->size-3;
y=i;
}
else{y=b->size-3;
x=i;
}

if (grid[x][y]) return 1;

}
return 0;
}





















