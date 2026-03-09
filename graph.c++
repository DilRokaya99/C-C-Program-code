#include <iostream>
#include <graphics.h>
#include <conio.h>
int main(){
    int gd,gm,x,y,i;
    gd=DETECT;
    initgraph(&gd, &gm, "C:\\TC\\bgi");
    x=getmaxx();
    y=getmaxy();
    for(i=0;i<=y;i+=10){
        rectangle(x/2-i, y/2-i, x/2+i, y/2+i);
    }
    getch();
    closeegraph();
    restorecrtmode();
    return 0;
}

