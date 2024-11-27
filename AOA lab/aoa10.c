// Implement N Queen's problem using Back Tracking.
#include <stdio.h>
#include<conio.h>

int row[100], cnt = 0, i,x, y;

int safe(int x, int y, int n);
void queen(int y, int n);
void printBoard(int n);

int safe(int x, int y, int n) {
    for(i = 0; i < y; i++) {
        if(row[i] == x || row[i] - i == x - y || row[i] + i == x + y) {
            return 0;
        }
    }
    return 1;
}

void printBoard(int n) {
    printf("\nOne of the solutions:\n");
    printf("---------------------------\n");
    for(y = 0; y < n; y++) {
        for( x = 0; x < n; x++) {
            if(row[y] == x) {
                printf("|Q ");
            } else {
                printf("|  ");
            }
        }
        printf("|\n");
        printf("---------------------------\n");
    }
}

void queen(int y, int n) {
    if(y == n) {
        cnt++;
        if(cnt == 1) {
            printBoard(n);
        }
        return;
    }
    for(int x = 0; x < n; x++) {
        row[y] = x;
        if(safe(x, y, n)) {
            queen(y + 1, n);
        }
    }
}

void  main() {
    int n;
     //clrscr();
    printf("Enter the size of the board : ");
    scanf("%d", &n);

    queen(0, n);
    printf("Total number of solutions: %d\n", cnt);
    //getch();

}
