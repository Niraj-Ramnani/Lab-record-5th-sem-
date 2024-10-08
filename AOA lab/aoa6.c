// From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm
// description : Dijkstra's algorithm finds the shortest path from one vertex to all other vertices. It does so by repeatedly selecting the nearest unvisited vertex and calculating the distance to all the unvisited neighboring vertices.
//source code 
#include <stdio.h>
#include<conio.h>
#define INF 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int visible[MAX] = {0}, count, miniDist, nextnode, i, j;


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0 && i != j) {  
                cost[i][j] = INF;
            } else {
                cost[i][j] = G[i][j];
            }
        }
    }


    for (i = 0; i < n; i++) {
        dist[i] = INF;  
        pred[i] = -1;   
        visible[i] = 0; 
    }
    dist[startnode] = 0; 

    count = 0; 
    while (count < n) {
        miniDist = INF;

       
        for (i = 0; i < n; i++) {
            if (!visible[i] && dist[i] < miniDist) {
                miniDist = dist[i];
                nextnode = i;
            }
        }

       
        visible[nextnode] = 1;
        count++;

     
        for (i = 0; i < n; i++) {
            if (!visible[i] && cost[nextnode][i] != INF) {
                if (miniDist + cost[nextnode][i] < dist[i]) {
                    dist[i] = miniDist + cost[nextnode][i];
                    pred[i] = nextnode; 
                }
            }
        }
    }

   
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("Distance from node %d to node %d is %d\n", startnode, i, dist[i]);
            if (dist[i] != INF) {
                printf("Path: %d", i);
                j = i;
                while (pred[j] != -1) {
                    printf(" <- %d", pred[j]);
                    j = pred[j];
                }
                printf("\n");
            } else {
                printf("No path exists to node %d\n", i);
            }
        }
    }
}

void main() {
    int G[MAX][MAX], i, j, n, u;
    //clrscr();
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &u);
    
    dijkstra(G, n, u);
    
    //getch();
}
