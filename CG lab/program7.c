// write a c program for composite 2d transformation
#include <stdio.h>
#include <graphics.h>
#include <math.h>

int round(float num) {
    return (num > 0.0) ? (int)(num + 0.5) : (int)(num - 0.5);
}

void drawShape(float p[][2], int np, int xc, int yc) {
    int i;
    for (i = 0; i < np; i++) {
        if (i != np - 1)
            line(round(p[i][0]) + xc, yc - round(p[i][1]), 
                 round(p[i + 1][0]) + xc, yc - round(p[i + 1][1]));
        else
            line(round(p[i][0]) + xc, yc - round(p[i][1]), 
                 round(p[0][0]) + xc, yc - round(p[0][1]));
    }
}

int main() {
    int gd = DETECT, gm, np, i, choice, cont = 1;
    int xcenter, ycenter, xmax, ymax;
    float p[10][2], tx, ty, theta, sx, sy, rad;
       initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter Number of Points: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++) {
	printf("\nEnter Coordinates of Point %d: ", i + 1);
	scanf("%f %f", &p[i][0], &p[i][1]);
    }


    xmax = getmaxx();
    ymax = getmaxy();
    xcenter = xmax / 2;
    ycenter = ymax / 2;

	setcolor(WHITE);
	drawShape(p, np, xcenter, ycenter);
    while (cont == 1) {
	
	setcolor(YELLOW);
	line(0, ycenter, xmax, ycenter);
	line(xcenter, 0, xcenter, ymax);


	printf("\nEnter Transformation Choice (1-Translation, 2-Rotation, 3-Scaling): ");
	scanf("%d", &choice);

	if (choice == 1) {
	    printf("Enter tx and ty: ");
	    scanf("%f %f", &tx, &ty);
	    for (i = 0; i < np; i++) {
		p[i][0] += tx;
		p[i][1] += ty;
            }
        } else if (choice == 2) {
            printf("Enter Angle in Degrees: ");
            scanf("%f", &theta);
            rad = (theta * M_PI) / 180;
            for (i = 0; i < np; i++) {
                float x = p[i][0], y = p[i][1];
                p[i][0] = x * cos(rad) - y * sin(rad);
                p[i][1] = x * sin(rad) + y * cos(rad);
            }
        } else if (choice == 3) {
            printf("Enter sx and sy: ");
            scanf("%f %f", &sx, &sy);
            for (i = 0; i < np; i++) {
                p[i][0] *= sx;
                p[i][1] *= sy;
            }
        } else {
            printf("Invalid Choice! Try again.\n");
        }

        setcolor(YELLOW);
        drawShape(p, np, xcenter, ycenter);
        printf("Try another option? Enter 1 to continue, 0 to exit: ");
        scanf("%d", &cont);
    }

    closegraph();
    return 0;
}
