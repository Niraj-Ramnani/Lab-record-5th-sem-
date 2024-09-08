//insertion sort
//aim : Write a c program to implement insertion sort 
//description : The algorithm takes one value at a time from the unsorted part of the array and puts it into the right place in the sorted part of the array its average and worst-case time complexity is O(n^2)
#include<stdio.h>
//#include<conio.h>
void display_arr(int arr[] , int n);
void insertion_sort(int arr[] , int n);
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
insertion_sort(arr,n);
printf("List after sorting \n");
display_arr(arr,n);
//getch();
}
void display_arr(int arr[] , int n ){
int i;
for(i = 0; i<n; i++){
printf("%d ",arr[i]);
}}
void insertion_sort(int arr[] , int n){
int temp,i,j;
for(i =1; i<n; i++){
temp = arr[i];
j = i -1;
while(j>=0 && arr[j]>temp){
arr[j+1] = arr[j];
arr[j] = temp;
j = j -1;
}}
}
// result : insertion sort is implemented and given list of array is sorted 