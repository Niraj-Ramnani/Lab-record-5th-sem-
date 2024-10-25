#include <stdio.h>

#define MAX 30

int Graph[MAX][MAX], i, j, n;

typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Kruskal's Algorithm
void kruskalAlgo() {
    int belongs[MAX], cno1, cno2;
    elist.n = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }
    }

    sort();

    for (i = 0; i < n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);

        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n++;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int find(int belongs[], int vertexno) {
    return belongs[vertexno];
}

void applyUnion(int belongs[], int c1, int c2) {
    for (i = 0; i < n; i++) {
        if (belongs[i] == c2)
            belongs[i] = c1;
    }
}

// Sorting algorithm
void sort() {
    int i, j;
    edge temp;

    for (i = 0; i < elist.n - 1; i++) {
        for (j = 0; j < elist.n - 1 - i; j++) {
            if (elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

void print() {
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < spanlist.n; i++) {
        printf("%d -- %d == %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    }
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the undirected graph (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &Graph[i][j]); 
        }
    }

    kruskalAlgo();
    print();

    return 0; 
}
