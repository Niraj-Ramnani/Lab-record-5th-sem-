// Midpoint Circle Theorem
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int xc, yc, r, p ,x ,y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the coordinates for the center of the circle (xc , yc): ");
    scanf("%d%d", &xc, &yc);

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);


     x = 0;
     y = r;


    p = 1 - r;


    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);

    while (x < y) {
	x++;
	if (p <= 0) {
	    p = p + 2 * x + 1;
	} else {
	    y--;
	    p = p + 2 * x - 2 * y + 1;
	}


	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc - x, WHITE);
    }

    getch();
    closegraph();
}
