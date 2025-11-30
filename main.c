#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"instructions.h"
#include"game.h"
#include"win.h"

int main() {
printf("\n\n\n\n");
printf(BRIGHT_MAGENTA
"████████╗██╗    ██╗██╗██╗  ██╗████████╗     ██████╗  █████╗ ███╗   ███╗███████╗\n"
"╚══██╔══╝██║    ██║██║╚██╗██╔╝╚══██╔══╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n"
"   ██║   ██║ █╗ ██║██║ ╚███╔╝    ██║       ██║  ███╗███████║██╔████╔██║█████╗  \n"
"   ██║   ██║███╗██║██║ ██╔██╗    ██║       ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  \n"
"   ██║   ╚███╔███╔╝██║██╔╝ ██╗   ██║       ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n\n\n\n"
RESET);

board b;
int x,y,choice,iop;


while(1){
printf(BRIGHT_GREEN"ENTER BOARD SIZE: "RESET);
scanf("%d", &iop);
if(iop>3) {iop=iop+2;break;}
printf("MINIMUM BOARDSIZE SHOULD BE 4\n");
}

makeboard(&b,iop);
resetboard(&b);
getchar();
menu(&b);

while(1){
gamestatus(&b);

printf("%s,ENTER ROW AND COLUMN (from 2 to %d): ",(b.curr==red)?"RED": "BLACK",b.size-3);
scanf("%d %d", &x, &y);

if(addpin(&b,x,y)==0) {
printf("INVALID MOVE, TRY AGAIN\n");
continue;
}

linkgeneration(&b, x, y);

if(checkwin(&b,b.curr)){gamestatus(&b);
if(b.curr==red) printf(BOLD RED"RED WINS THE GAME"RESET);
else printf(BOLD BLUE"BLACK WINS THE GAME"RESET);
freeboard(&b);
quitgame();
}

switchplayer(&b);
printf("\n1. CONTINUE \n");
printf("2. RESTART \n");
printf("3. EXIT\n");
printf("4. SHOW MENU AND CONTINUE\n");
printf("5. SHOW LINKS AND CONTINUE\n");
printf("CHOICE: ");

scanf("%d", &choice);
printf("\033[2J\033[H");
if (choice==2) {
    // printf("\033[2J\033[H");
    resetboard(&b);}

else if (choice== 3){
    freeboard(&b);
    quitgame();}
else if(choice== 4) {
    // printf("\033[2J\033[H");
    menu(&b);}
else if(choice==5) {
    // printf("\033[2J\033[H");
printlink(&b);}
}
    return 0;
}
