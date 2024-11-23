// write a c program for the  Implementation of ellipse generating Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm;
 float p,x,y,xc,yc,a,b;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 cleardevice();
 printf("Enter xc, yc:\n");
 scanf("%f%f",&xc,&yc);
 printf("Enter a, b:\n");
 scanf("%f%f",&a,&b);
 x=0;
 y=b;
 p=(b*b)-(a*a*b)+(0.25*a*a);
 do
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p<0)
  {
   x=x+1;
   p=p+2*b*b*x+b*b;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p+2*b*b*x-2*a*a*y+b*b;
  }
 }while(2*b*b*x<2*a*a*y);

 p=(b*b*(x+0.5)*(x+0.5))+((y-1)*(y-1)*a*a-a*a*b*b);
 do
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p>0)
  {
   y=y-1;
   p=p-2*a*a*y+a*a;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p-2*a*a*y+2*b*b*x+a*a;
  }
 }while(y!=0);
 getch();
 closegraph();
}