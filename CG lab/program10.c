// write a c program to implement  Three dimensional transformations-Translation, Rotation, Scaling
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

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

void translateCube(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y -= ty;
}

void scaleCube(int *sz, float sx) {
    *sz = (int)(*sz * sx);
}

void rotateCube(int *x, int *y, int angle, int xc, int yc, int axis) {
    float rad = angle * (M_PI / 180.0);
    int tx = *x - xc, ty = *y - yc;
    int nx, ny;

    if (axis == 1) {
        nx = tx;
        ny = (int)(ty * cos(rad) - tx * sin(rad));
    } else if (axis == 2) {
        nx = (int)(tx * cos(rad) - ty * sin(rad));
        ny = ty;
    } else {
        nx = (int)(tx * cos(rad) - ty * sin(rad));
        ny = (int)(tx * sin(rad) + ty * cos(rad));
    }

    *x = nx + xc;
    *y = ny + yc;
}

int main() {
    int gd = DETECT, gm;
    int xmax, ymax, xc, yc;
    int x, y, sz, cont = 1, choice;
    int tx, ty, angle, axis;
    float sx;

    initgraph(&gd, &gm, "C:\\turboc3\\BGI");

    xmax = getmaxx();
    ymax = getmaxy();
    xc = xmax / 2;
    yc = ymax / 2;

    printf("Enter Cube size: ");
    scanf("%d", &sz);

    printf("Enter initial Cube coordinates (x y): ");
    scanf("%d %d", &x, &y);

    x = abs(x);
    y = -abs(y);

    while (cont == 1) {
        cleardevice();
        setcolor(YELLOW);
        line(0, yc, xmax, yc);
        line(xc, 0, xc, ymax);
        drawCube(xc, yc, x, y, sz, WHITE);

        printf("\nMenu:\n");
        printf("1. Translation\n");
        printf("2. Scaling\n");
        printf("3. Rotation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation factors (tx ty): ");
                scanf("%d %d", &tx, &ty);
                translateCube(&x, &y, tx, ty);
                drawCube(xc, yc, x, y, sz, RED);
                break;

            case 2:
		printf("Enter scaling factor (s): ");
                scanf("%f", &sx);
                scaleCube(&sz, sx);
                drawCube(xc, yc, x, y, sz, GREEN);
                break;

            case 3:
                printf("Enter angle of rotation (in degrees): ");
                scanf("%d", &angle);
                printf("Choose axis of rotation:\n");
                printf("1. X-axis\n2. Y-axis\n3. Origin\n");
                printf("Enter your choice: ");
                scanf("%d", &axis);
                rotateCube(&x, &y, angle, xc, yc, axis);
                drawCube(xc, yc, x, y, sz, BLUE);
                break;

            case 4:
                cont = 0;
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\nPress any key to continue...\n");
        getch();
    }

    closegraph();
    return 0;
}
