// To plot a point (pixel) on the screen
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
int gd = DETECT;
int gm;
int x =100 , y 150;
initgraph(&gd , &gm , "C:\\TC\\BGI");
putpixel(x,y,WHITE);
getch();
closegraph();
return 0;
}