//aim : write a c program To draw a straight line using DDA Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
int x1,y1,x2,y2,n,dx,dy,i;
float xinc,yinc,xnxt,ynxt;
int gd = DETECT,gm;

clrscr();
initgraph(&gd , &gm , "C:\\TC\\BGI");
printf("Enter the values for x1,y1 : ");
scanf("%d%d",&x1,&y1);
printf("Enter the value for x2,y2 : ");
scanf("%d%d",&x2,&y2);
dx = x2 - x1;
dy = y2 - y1;
n = (dx>dy)?dx :dy;
xinc = dx/(float)n;
yinc = dy/(float)n;
xnxt = x1;
ynxt = y1;

for(i = 0; i<n; i++){
putpixel((int)xnxt,(int)ynxt,YELLOW);
xnxt = xnxt + xinc;
ynxt = ynxt + yinc;
}
getch();
closegraph();
}