// write a c progrm for  Composite 3D transformations
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int xc = 200, yc = 150, x = 50, y = 50, sz = 50, col = YELLOW, tx = 100, ty = 40;
float sx = 1.5, sy = 1.5, angle = 50;

void translate(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

void scale(int *sz, float sx, float sy) {
    *sz = *sz * sx;
}

void rotateZ(int *x, int *y, float angle) {
    float rad = angle * (PI / 180);
    int newX = *x * cos(rad) - *y * sin(rad);
    int newY = *x * sin(rad) + *y * cos(rad);
    *x = newX;
    *y = newY;
}

void drawCube(int xc, int yc, int x, int y, int sz, int col) {
    int f = (sz * 30) / 100;
    setcolor(col);
    rectangle(xc + x, yc + y, xc + x + sz, yc + y + sz);
    rectangle(xc + x + f, yc + y + f, xc + x + sz + f, yc + y + sz + f);
    line(xc + x, yc + y, xc + x + f, yc + y + f);
    line(xc + x + sz, yc + y + sz, xc + x + sz + f, yc + y + sz + f);
    line(xc + sz + x, yc + y, xc + sz + x + f, yc + y + f);
    line(xc + x, yc + y + sz, xc + x + f, yc + y + sz + f);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\BGI");
    drawCube(xc, yc, x, y, sz, WHITE);
    translate(&x, &y, tx, ty);
    scale(&sz, sx, sy);
    rotateZ(&x, &y, angle);

    drawCube(xc, yc, x, y, sz, col);

    getch();
    closegraph();
    return 0;
}
