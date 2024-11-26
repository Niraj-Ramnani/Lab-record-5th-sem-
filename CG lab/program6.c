// write a c program to implement two dimensional transformations (translation , rotation , scaling , reflection , shear)
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
        y[i] -= ty;
    }
}

void scale(int x[], int y[], int n, float sx, float sy) {
    int i, centroidX = 0, centroidY = 0;
    for (i = 0; i < n; i++) {
        centroidX += x[i];
        centroidY += y[i];
    }
    centroidX /= n;
    centroidY /= n;

    for (i = 0; i < n; i++) {
        x[i] = centroidX + (int)((x[i] - centroidX) * sx);
        y[i] = centroidY + (int)((y[i] - centroidY) * sy);
    }
}

void reflect(int x[], int y[], int n, int axis, int midX, int midY) {
    int i;
    for (i = 0; i < n; i++) {
        if (axis == 1) {
            y[i] = 2 * midY - y[i];
        } else if (axis == 2) {
            x[i] = 2 * midX - x[i];
        } else if (axis == 3) {
            x[i] = 2 * midX - x[i];
            y[i] = 2 * midY - y[i];
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
    int midX, midY;
    int x[3] = {100, 200, 150};
    int y[3] = {150, 200, 100};
    int n = 3;
    int choice, tx, ty, axis, shx, shy;
    float sx, sy, angle;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    midX = getmaxx() / 2;
    midY = getmaxy() / 2;

    setcolor(YELLOW);
    line(0, midY, getmaxx(), midY);
    line(midX, 0, midX, getmaxy());

    while (1) {
        cleardevice();
        setcolor(YELLOW);
        line(0, midY, getmaxx(), midY);
        line(midX, 0, midX, getmaxy());

        drawPolygon(x, y, n, WHITE);

        printf("\nMenu:\n");
        printf("1. Translation\n");
        printf("2. Scaling\n");
        printf("3. Reflection\n");
        printf("4. Shearing\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation factors (tx ty): ");
                scanf("%d %d", &tx, &ty);
                translate(x, y, n, tx, ty);
                drawPolygon(x, y, n, RED);
                break;

            case 2:
                printf("Enter scaling factors (sx sy): ");
                scanf("%f %f", &sx, &sy);
                scale(x, y, n, sx, sy);
                drawPolygon(x, y, n, GREEN);
                break;

            case 3:
                printf("Choose axis of reflection:\n");
                printf("1. X-axis\n2. Y-axis\n3. Origin\n");
                printf("Enter your choice: ");
                scanf("%d", &axis);
                reflect(x, y, n, axis, midX, midY);
                drawPolygon(x, y, n, BLUE);
                break;

            case 4:
                printf("Enter shearing factors (shx shy): ");
                scanf("%d %d", &shx, &shy);
                shear(x, y, n, shx, shy);
                drawPolygon(x, y, n, CYAN);
                break;

            case 5:
                closegraph();
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\nPress any key to continue...\n");
        getch();
    }

    closegraph();
    return 0;
}
