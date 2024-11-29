// write a c program for Generating Fractal images
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000
#define ZOOM 150
double x,y,r,temp,iVal;
int it;
int mandelbrot(double r, double i) {
     x = 0.0, y = 0.0;
    it = 0;
    while (x*x + y*y <= 4.0 && it < MAX_ITER) {
	temp = x*x - y*y + r;
	y = 2*x*y + i;
	x = temp;
	it++;
    }
    return it;
}

int main() {
    int gd = DETECT, gm, color, i, j;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    for (i = 0; i < WIDTH; i++) {
	for (j = 0; j < HEIGHT; j++) {
	    r = (i - WIDTH / 2.0) / ZOOM;
	    iVal = (j - HEIGHT / 2.0) / ZOOM;
	     it = mandelbrot(r, iVal);
	    color = (it == MAX_ITER) ? 0 : (it % 256);
	    putpixel(i, j, color);
	}
    }

    getch();
    closegraph();
    return 0;
}
