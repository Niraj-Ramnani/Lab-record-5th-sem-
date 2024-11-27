//Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int i, j, k, a, b, u, v, ne = 1;
int n, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

void main(){
    printf("\n\t Implementation of Kruskal's Algorithm \n");
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) cost[i][j] = 999;
        }
    }

    printf("The edges of the minimum cost spanning tree are: \n");

    while(ne < n){
        int min = 999;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if(uni(u, v)){
            printf("Edge %d: (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i){
    while(parent[i]){
        i = parent[i];
    }
    return i;
}

int uni(int i, int j){
    int root_i = find(i);
    int root_j = find(j);

    if(root_i != root_j){
        parent[root_j] = root_i;
        return 1;
    }
    return 0;
}
