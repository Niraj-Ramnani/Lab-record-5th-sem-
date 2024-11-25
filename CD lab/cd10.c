// write a c program to calculate the first of a given grammer 
#include <stdio.h>
#include<conio.h>
#include <string.h>

#define MAX 10

struct rule {
    char nt;
    char prod[MAX][MAX];
    int pc;
} g[MAX];

char first[MAX][MAX];
int fc[MAX] = {0};
int visited[MAX] = {0};
int i,j,p,nti;
char nt;
int isTerm(char c) {
    return (c >= 'a' && c <= 'z');
}

int getIdx(char nt) {
    for ( i = 0; i < MAX; i++) {
        if (g[i].nt == nt) return i;
    }
    return -1;
}

int inFirst(int idx, char c) {
    for ( i = 0; i < fc[idx]; i++) {
        if (first[idx][i] == c) return 1;
    }
    return 0;
}

void calcFirst(int idx) {
    if (visited[idx]) return;
    visited[idx] = 1;

     nt = g[idx].nt;

    for ( p = 0; p < g[idx].pc; p++) {
        char* prod = g[idx].prod[p];

        if (isTerm(prod[0])) {
            if (!inFirst(idx, prod[0])) {
                first[idx][fc[idx]++] = prod[0];
            }
        }
        else {
             nti = getIdx(prod[0]);
            if (nti != -1) {
                calcFirst(nti);  

                for ( i = 0; i < fc[nti]; i++) {
                    if (!inFirst(idx, first[nti][i])) {
                        first[idx][fc[idx]++] = first[nti][i];
                    }
                }
            }
        }
    }
}

void print() {
    for ( i = 0; i < MAX; i++) {
        if (g[i].nt != '\0') {
            printf("First(%c) = { ", g[i].nt);
            for (j = 0; j < fc[i]; j++) {
                printf("%c ", first[i][j]);
            }
            printf("}\n");
        }
    }
}

void main() {
    int n;
    //clrscr();
    printf("Enter number of rules: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("Enter non-terminal for rule %d: ", i + 1);
        scanf(" %c", &g[i].nt);

        printf("Enter number of productions for %c: ", g[i].nt);
        scanf("%d", &g[i].pc);

        for ( j = 0; j < g[i].pc; j++) {
            printf("Enter production %d for %c: ", j + 1, g[i].nt);
            scanf("%s", g[i].prod[j]);
        }
    }

    for ( i = 0; i < n; i++) {
        calcFirst(i);
    }

    print();
    // getch();

}
