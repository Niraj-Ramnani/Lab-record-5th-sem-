//aim : Write a c program to implement bubble sort 
//description : traverse from left and compare adjacent elements and the higher one is placed at right side. its average and worst-case time complexity is O(n^2)
//source code :
#include<stdio.h>
//#include<conio.h>
void display_arr(int arr[] , int n);
void bubble_sort(int arr[] , int n);
void main(){
int temp,n,i;
int arr[50];
//clrscr();
printf("Enter the number of the elemnts for the array : ");
scanf("%d",&n);
printf("Enter the elements of the array \n");
for(i =0; i<n; i++){
scanf("%d",&arr[i]);
}
bubble_sort(arr,n);
printf("List after sorting \n");
display_arr(arr,n);
//getch();
}
void display_arr(int arr[] , int n ){
int i;
for(i = 0; i<n; i++){
printf("%d ",arr[i]);
}}
void bubble_sort(int arr[] , int n){
int i,j,temp;
for(i =0; i<n; i++){
for(j = 0; j<n - i - 1; j ++){
if(arr[j]>arr[j+1]){
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;}
}}
}
// result : Bubble sort is implemented and given list of array is sorted 