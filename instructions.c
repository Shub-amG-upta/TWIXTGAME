
#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include"colour.h"
#include<string.h>


#define REDBOLD  "\033[1;31m"
#define BLUEBOLD  "\033[1;34m"
#define CYANBOLD  "\033[1;36m"
#define GREYBG   "\033[47m"
#define DARKBG  "\033[100m"
#define RESET    "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

void menu(board*b) {
    printf("========================================\n");
    printf("          Welcome to Twixt Game         \n");
    printf("========================================\n\n");
    printf("RULES:\n");
    printf("- Red player has to connect from TOP to BOTTOM\n");
    printf("- Black player has to connect from LEFT to RIGHT\n");
    printf("- Place pins on valid positions (not in corners)\n");
    printf("- pins link automatically that are knight's move apart\n");
    printf("- Links cannot cross each other\n");
    printf("- First player to connect their borders wins!\n\n");
    printf("- Board size: %dx%d (corners removed)\n",b->size-2,b->size-2);
    printf("========================================\n\n");
    char buffer[20];
    printf("\nPRESS ENTER TO START GAME...");
fgets(buffer, sizeof(buffer), stdin);
}


void gamestatus(board*b) {
    // printf("\033[2J\033[H");

    printf("========================================\n");
    printf(GREYBG"              Twixt Game                "RESET);printf("\n");
    printf("========================================\n");
    if(b->curr==red) printf(REDBOLD"CURRENT PLAYER: RED\n"RESET);
    else printf(BLUEBOLD"CURRENT PLAYER: BLACK\n"RESET);
    printf(REDBOLD"RED PINS: %d |"RESET,b->redcount); printf(BLUEBOLD" BLACK PINS: %d\n"RESET,b->blackcount);
    printf("========================================\n");
    printboard(b);
    printf("========================================\n");
  
}

void printlink(board*b){

link*l=b->links;
if(l==NULL) {printf("NO LINKS FOUND");return;}
printf("======LINKS======\n");
while(l!=NULL){
if(l->curr==red){
printf(RED"(%d,%d) <--> (%d,%d) RED\n"RESET,l->x1,l->y1,l->x2,l->y2);}
else{
printf(BLUE"(%d,%d) <--> (%d,%d) BLUE\n"RESET,l->x1,l->y1,l->x2,l->y2);
}
l=l->next;
}
printf("================\n");
}

