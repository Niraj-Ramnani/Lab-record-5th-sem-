// write a c program to implement  Sutherland–Hodgeman Polygon clipping Algorithm
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void clip(int p[][2], int *np, int x1, int y1, int x2, int y2) {
    int newp[20][2], newnp = 0;
    int i, k, xi, yi, xk, yk, iPos, kPos, xIntersect, yIntersect;

    for (i = 0; i < *np; i++) {
        k = (i + 1) % *np;
        xi = p[i][0];
        yi = p[i][1];
        xk = p[k][0];
        yk = p[k][1];

        iPos = (xi - x1) * (y2 - y1) - (yi - y1) * (x2 - x1);
        kPos = (xk - x1) * (y2 - y1) - (yk - y1) * (x2 - x1);

        if (iPos >= 0 && kPos >= 0) {
            newp[newnp][0] = xk;
            newp[newnp++][1] = yk;
        } else if (iPos >= 0 && kPos < 0) {
            xIntersect = xi + (xk - xi) * abs(iPos) / (abs(iPos) + abs(kPos));
            yIntersect = yi + (yk - yi) * abs(iPos) / (abs(iPos) + abs(kPos));
            newp[newnp][0] = xIntersect;
            newp[newnp++][1] = yIntersect;
        } else if (iPos < 0 && kPos >= 0) {
            xIntersect = xi + (xk - xi) * abs(iPos) / (abs(iPos) + abs(kPos));
            yIntersect = yi + (yk - yi) * abs(iPos) / (abs(iPos) + abs(kPos));
            newp[newnp][0] = xIntersect;
            newp[newnp++][1] = yIntersect;
            newp[newnp][0] = xk;
            newp[newnp++][1] = yk;
        }
    }

    *np = newnp;

    for (i = 0; i < *np; i++) {
        p[i][0] = newp[i][0];
        p[i][1] = newp[i][1];
    }
}

void main() {
    int gd = DETECT, gm, np, i, x1, y1, x2, y2;
    int p[10][2];

    clrscr();
    printf("Enter Number of Polygon Points: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++) {
        printf("Enter Point %d (x y): ", i + 1);
        scanf("%d %d", &p[i][0], &p[i][1]);
    }

    printf("Enter Clipping Window (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    cleardevice();

    rectangle(x1, y1, x2, y2);

    setcolor(RED);
    for (i = 0; i < np; i++) {
        if (i != np - 1)
            line(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
        else
            line(p[i][0], p[i][1], p[0][0], p[0][1]);
    }

    clip(p, &np, x1, y1, x2, y1);
    clip(p, &np, x2, y1, x2, y2);
    clip(p, &np, x2, y2, x1, y2);
    clip(p, &np, x1, y2, x1, y1);

    setcolor(GREEN);
    for (i = 0; i < np; i++) {
        if (i != np - 1)
            line(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
        else
            line(p[i][0], p[i][1], p[0][0], p[0][1]);
    }

    getch();
    closegraph();
}
