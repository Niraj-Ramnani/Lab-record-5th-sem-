// aim : write a c program to implement topological sort using dfs
// description : Topological sort using DFS  for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering by visiting all vertices, marking them as visited, and adds them to a stack after exploring their neighbors. The stack is then popped to produce a linear ordering of vertices, ensuring that each vertex appears before its dependents.
//source code 
#include<stdio.h>
//#include<conio.h>
int n, arr[10][10] , indegree[10],i,j ;
void count_indegree(){
int sum;
for(j = 0; j < n; j++){
sum = 0;
for(i = 0; i < n ; i++){
sum += arr[i][j];
}
indegree[j] = sum;
}}
void topology_sort(){
int u,v,stack[10],t[10],top = -1 , k = 0;
count_indegree();
for(i = 0; i<n; i++){
if(indegree[i] == 0 ){
stack[++top] = i ;}}
while(top != -1 ){
u = stack[top--];
t[k++] = u;
for(v = 0; v < n ; v ++){
if(arr[u][v] == 1){
indegree[v]--;
if(indegree[v] == 0){
stack[++top] = v;
}}
}}
printf("Topological sort of the given graph is \n");
for(i = 0; i < n ; i ++){
printf("%d  ",t[i]);
}}
void main(){
//clrscr();
printf("Enter the total number of the nodes : ");
scanf("%d",&n);
printf("Enter the adjancey matrix for the graph \n");
for(i = 0 ; i < n; i ++){
for(j = 0 ; j < n; j++){
scanf("%d",&arr[i][j]);
}}
topology_sort();
//getch();
}
// result : Toplogical sort is implemented using DFS