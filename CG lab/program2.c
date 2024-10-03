//aim : write a c program for the Implementation of Line, Circle andellipse attributes
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
int gd = DETECT , gm;
initgraph( &gd , &gm ,"C:\\TC\\BGI");
circle(200,100,80);
line(100,250,250,250);
ellipse(200,400,0,360,100,50);
getch();
closegraph();
}