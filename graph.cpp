#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main(){
    int gm,gd,x,y;
    gd=DETECT;
    intgraph(&gd, &gm, "C:\\TC\\bgi");
    x=getmaxx();
    y=getmaxy();
    line(0,0,x,y);
    line(0,y,x,0);
    line(0,y/2,x,y/2);
    line(x/2,0,x/2,y);
    getch();s
    closehraph();
    restotrcrtmode();
    return 0;
}