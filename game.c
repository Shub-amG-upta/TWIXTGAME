
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"game.h"
#include"colour.h"

void resetboard(board *b){
for(int i=0;i<b->size;i++){
for(int j=0;j<b->size;j++){
b->cells[i][j].pin = empty;
}
}
link *buff=b->links;
while(buff!=NULL){
link*temp=buff;
buff=buff->next;free(temp);
}
b->links=NULL;
b->redcount = 0;
b->blackcount = 0;
b->curr = red;
}

int addpin(board*b,int x,int y){
// printf("x=%d y=%d",x,y);
if (x<0||x>=b->size||y< 0||y>=b->size){
printf("ENTER VALID COORINATES...\n");
printf("COORDINATES OUT OF BOUND....\n");
return 0;
}

if (x<2||x>b->size-3||y<2||y>b->size-3) {
printf("ENTER VALID COORINATES...\n");
printf("YOU CAN ONLY PLACE PINS INSIDE THE 22x22 STAR BOX!\n");
return 0;
}

if (b->cells[x][y].pin !=empty) {
printf("ENTER VALID COORDIANTES...");
printf("COORDINATES ALREADY USED...\n");
return 0;
}

b->cells[x][y].pin = b->curr;

if (b->curr==red) b->redcount++;
else b->blackcount++;

return 1;
}


void switchplayer(board *b){
if(b->curr==red) b->curr=black;
else b->curr=red;
}

void printboard(board *b) {

for (int r=0;r<b->size;r++) {
    // printf("%d ", r);
for (int c=0;c<b->size;c++) {
// printf("%d", c);
if ((r==0&&c==0)||(r==0&&c==b->size-1)||(r==b->size-1&&c==0)||(r==b->size-1&&c==b->size-1)) {
printf("  ");
continue;
}

if (r==0||r==b->size-1){
printf(RED". "RESET);
continue;
}
if (c==0||c==b->size-1){
printf(BLUE". "RESET);
continue;
}

if ((r ==1||r==b->size-2)&& (c>=1&&c<=b->size-2)) { printf(CYANBOLD"* "RESET);continue;}
if ((c==1||c==b->size-2)&&(r>=1&&r<=b->size-2)) { printf(CYANBOLD"* "RESET);continue;}

if (b->cells[r][c].pin ==empty) printf(". ");
else if(b->cells[r][c].pin ==red) printf( REDBOLD"R "RESET);
else printf( BLUEBOLD"B "RESET);
}

        printf("\n");

    }
}

void restartgame(board *b){
resetboard(b);
printf("GAME RESTARTED...");
}

void quitgame(){
printf("ENDING PROGRAM....");
exit(0);
}

void makeboard(board*b,int s) {
b->size=s;
b->cells=malloc(s*sizeof(Cell*));
for (int i=0;i<s;i++)  b->cells[i]=malloc(s*sizeof(Cell));
b->links=NULL;
}

void freeboard(board *b) {
link *buff=b->links;
while(buff!=NULL){
link*temp=buff;
buff=buff->next;free(temp);
}
b->links=NULL;

for (int i = 0; i < b->size; i++) free(b->cells[i]);
free(b->cells);
}

void addlink(board*b,int x1,int y1,int x2,int y2,status buff){

link* new=malloc(sizeof(link));
new->x1=x1;new->y1=y1;
new->x2=x2;new->y2=y2;
new->curr=buff;
new->next=b->links;
b->links=new;
}
int checklink(board*b,int x1,int y1,int x2,int y2){

link* l=b->links;
while(l!=NULL){
if((l->x1==x1 &&l->x2==x2&&l->y1==y1&&l->y2==y2)||(l->x1==x2&&l->x2==x1&&l->y1==y2&&l->y2==y1)) return 1;
l=l->next;
}
return 0;
}

int crosslink(board *b,int x1,int y1,int x2,int y2){
link*l=b->links;

int buffx=abs(x1-x2);
int buffy=abs(y1-y2);
if(!((buffx==1&&buffy==2)||(buffx==2&&buffy==1))) return 0;
while(l!=NULL){
if((l->x1==x1 && l->y1==y2 && l->x2==x2 && l->y2==y1)||(l->x1==x2 && l->y1==y2 && l->x2==x1 && l->y2==y1)) return 1;
l=l->next;
}
return 0;
}

void linkgeneration(board*b,int x,int y){
status buffs=b->curr;
int varx[]={2,1,1,-2,-2,2,-1,-1};
int vary[]={1,2,-2,1,-1,-1,-2,2};
for(int i=0;i<8;i++){
int buffx=x+varx[i];
int buffy=y+vary[i];

if(buffx<0||buffx>=b->size||buffy<0||buffy>=b->size) continue;
if(b->cells[buffx][buffy].pin!=buffs) continue;
if(checklink(b,x,y,buffx,buffy)) continue;
if(crosslink(b,x,y,buffx,buffy)) continue;

addlink(b,x,y,buffx,buffy,buffs);
}

}





