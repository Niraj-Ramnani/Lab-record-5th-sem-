// write a c program for Two Dimensional transformations-Translation, Rotation, Scaling, Reflection, Shear
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void drawPolygon(int x[], int y[], int n, int color) {
    int i;
    setcolor(color);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);
}

void translate(int x[], int y[], int n, int tx, int ty) {
    int i;
    for (i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

void scale(int x[], int y[], int n, float sx, float sy) {
    int i, centroidX = 0, centroidY = 0;
    // Calculate the centroid of the polygon
    for (i = 0; i < n; i++) {
        centroidX += x[i];
        centroidY += y[i];
    }
    centroidX /= n;
    centroidY /= n;

    // Scale around the centroid
    for (i = 0; i < n; i++) {
        x[i] = (int)(centroidX + (x[i] - centroidX) * sx);
        y[i] = (int)(centroidY + (y[i] - centroidY) * sy);
    }
}

void rotate(int x[], int y[], int n, float angle) {
    float radian = angle * (3.14159 / 180.0);
    int i, tempX, tempY;
    for (i = 0; i < n; i++) {
        tempX = (int)(x[i] * cos(radian) - y[i] * sin(radian));
        tempY = (int)(x[i] * sin(radian) + y[i] * cos(radian));
        x[i] = tempX;
        y[i] = tempY;
    }
}

void reflect(int x[], int y[], int n, int axis) {
    int i;
    for (i = 0; i < n; i++) {
        if (axis == 1) {  // Reflect over X-axis
            y[i] = -y[i];
        } else if (axis == 2) {  // Reflect over Y-axis
            x[i] = -x[i];
        } else if (axis == 3) {  // Reflect over Origin
            x[i] = -x[i];
            y[i] = -y[i];
        }
    }
}

void shear(int x[], int y[], int n, int shx, int shy) {
    int i, tempX;
    for (i = 0; i < n; i++) {
        tempX = x[i];
        x[i] += shx * y[i];
        y[i] += shy * tempX;
    }
}

int main() {
    int gd = DETECT, gm;
    int x[3] = {100, 200, 150};
    int y[3] = {100, 150, 75};
    int n = 3;
    int choice, tx, ty, axis, shx, shy;
    float sx, sy, angle;
    int backgroundColor = WHITE;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawPolygon(x, y, n, backgroundColor);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Translation\n");
        printf("2. Scaling\n");
        printf("3. Rotation\n");
        printf("4. Reflection\n");
        printf("5. Shearing\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation factors (tx ty): ");
                scanf("%d %d", &tx, &ty);
                cleardevice();
                drawPolygon(x, y, n, backgroundColor);
                translate(x, y, n, tx, ty);
                drawPolygon(x, y, n, RED);
                break;

            case 2:
                printf("Enter scaling factors (sx sy): ");
                scanf("%f %f", &sx, &sy);
                cleardevice();
                drawPolygon(x, y, n, backgroundColor);
                scale(x, y, n, sx, sy);
                drawPolygon(x, y, n, GREEN);
                break;

            case 3:
                printf("Enter angle of rotation (in degrees): ");
                scanf("%f", &angle);
                cleardevice();
                drawPolygon(x, y, n, backgroundColor);
                rotate(x, y, n, angle);
                drawPolygon(x, y, n, BLUE);
                break;

            case 4:
                printf("Choose axis of reflection:\n");
                printf("1. X-axis\n2. Y-axis\n3. Origin\n");
                printf("Enter your choice: ");
                scanf("%d", &axis);
                cleardevice();
                drawPolygon(x, y, n, backgroundColor);
                reflect(x, y, n, axis);
                drawPolygon(x, y, n, YELLOW);
                break;

            case 5:
                printf("Enter shearing factors (shx shy): ");
                scanf("%d %d", &shx, &shy);
                cleardevice();
                drawPolygon(x, y, n, backgroundColor);
                shear(x, y, n, shx, shy);
                drawPolygon(x, y, n, CYAN);
                break;

            case 6:
                closegraph();
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\nPress any key to continue...\n");
        getch();
    }

    getch();
    closegraph();
    return 0;
}
