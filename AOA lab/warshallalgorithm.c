//aim : Compute the transitive closure of a given directed graph using Warshall's algorithm.
//description : Warshall's algorithm computes the transitive closure of a directed graph by determining the reachability between all pairs of vertices. updates the adjacency matrix to reflect whether a path exists between nodes and finding the shortest path 
#include<stdio.h>
//#include<conio.h>
int i,j,k,n,arr[10][10];

void warshall(){
for(k = 0; k<n; k++){
for(i = 0; i<n; i++){
for(j = 0; j<n; j++){
if(arr[i][k] != 0 && arr[k][j] !=  0){
     if(arr[i][j] == 0){
          arr[i][j] = arr[i][k] + arr[k][j];
     }
     else{
 arr[i][j] = min(arr[i][j] , (arr[i][k] + arr[k][j]));}}
}}}
}

int min(int a , int b){
if(a<b) return a;
else return b;
}
void main(){
//clrscr();
printf("Enter the number of the nodes in the graph ");
scanf("%d",&n);
printf("Enter the adjancey matrix of the graph \n");
for(i = 0; i<n; i++){
for(j = 0; j<n; j++){
scanf("%d",&arr[i][j]);}}
warshall();
printf("transitive closure of a given directed graph is  \n");
for(i = 0; i<n; i++){
for(j = 0; j<n; j++){
printf("%d ",arr[i][j]);}
printf("\n");}
//getch();
}
//result : transitive closure matrix of the given graph is generated 