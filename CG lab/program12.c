// write a c program for Drawing three dimensional objects and Scenes
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void rotateY(float *x, float *z, float angle) {
    float tempX = *x;
    *x = *x * cos(angle) - *z * sin(angle);
    *z = tempX * sin(angle) + *z * cos(angle);
}

void project(float x, float y, float z, int *x2D, int *y2D, int viewDist) {
    *x2D = (int)(x * viewDist / (z + viewDist));
    *y2D = (int)(y * viewDist / (z + viewDist));
}

int main() {
    int gd = DETECT, gm;
    int cx, cy, i;
    float angle = 0.05;
    int x2D[8], y2D[8];

    float cube[8][3] = {
        {-50, -50, -50},
        { 50, -50, -50},
        { 50,  50, -50},
        {-50,  50, -50},
        {-50, -50,  50},
        { 50, -50,  50},
        { 50,  50,  50},
        {-50,  50,  50}
    };

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    cx = getmaxx() / 2;
    cy = getmaxy() / 2;

    while (!kbhit()) {
        cleardevice();

        for (i = 0; i < 8; i++) {
            rotateY(&cube[i][0], &cube[i][2], angle);
        }

        for (i = 0; i < 8; i++) {
            project(cube[i][0], cube[i][1], cube[i][2], &x2D[i], &y2D[i], 200);
            x2D[i] += cx;
            y2D[i] += cy;
        }

        for (i = 0; i < 4; i++) {
            line(x2D[i], y2D[i], x2D[(i + 1) % 4], y2D[(i + 1) % 4]);
            line(x2D[i + 4], y2D[i + 4], x2D[((i + 1) % 4) + 4], y2D[((i + 1) % 4) + 4]);
            line(x2D[i], y2D[i], x2D[i + 4], y2D[i + 4]);
        }

        line(x2D[0], y2D[0], x2D[4], y2D[4]);
        line(x2D[1], y2D[1], x2D[5], y2D[5]);
        line(x2D[2], y2D[2], x2D[6], y2D[6]);
        line(x2D[3], y2D[3], x2D[7], y2D[7]);

        delay(10);
    }

    closegraph();
    return 0;
}
