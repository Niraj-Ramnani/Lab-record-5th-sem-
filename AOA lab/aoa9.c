//Find Minimum Cost Spanning Tree of a givenundirected graph using Prim’s algorithm.
#include<stdio.h>
#include<conio.h>
int g[20][20], d[20], visited[20], p[20];
int v, e;

void createGraph();
void prims();

int main() {
    createGraph();
    prims();
    return 0;
}

void createGraph() {
    int a, b, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    if (e < v - 1) {
        printf("Not enough edges to form a spanning tree.\n");
        return;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g[i][j] = 0;
        }
    }

    for (int i = 0; i < v; i++) {
        p[i] = -1;
        visited[i] = 0;
        d[i] = 32767;
    }

    for (int i = 0; i < e; i++) {
        printf("Enter edge (a, b) and weight w: ");
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        g[a][b] = g[b][a] = w;
    }
}

void prims() {
    int totalVisited = 0, mincost = 0, current = 0;

    d[current] = 0;
    p[current] = -1;

    while (totalVisited < v) {
        int min = 32767, minIndex = -1;
        for (int i = 0; i < v; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            printf("Graph is disconnected. Minimum spanning tree cannot include all vertices.\n");
            return;
        }

        current = minIndex;
        visited[current] = 1;
        mincost += d[current];
        totalVisited++;

        for (int i = 0; i < v; i++) {
            if (g[current][i] && !visited[i] && g[current][i] < d[i]) {
                d[i] = g[current][i];
                p[i] = current;
            }
        }
    }

    printf("Minimum cost of the spanning tree: %d\n", mincost);
    printf("Edges in the minimum spanning tree:\n");
    for (int i = 0; i < v; i++) {
        if (p[i] != -1) {
            printf("Edge: %d - %d, Weight: %d\n", p[i] + 1, i + 1, g[p[i]][i]);
        }
    }
}
