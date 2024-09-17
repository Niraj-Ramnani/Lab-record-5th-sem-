// aim : write a c program to implement quick sort 
// description : It is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array . Quick sort average time complexity is O (n log n)
#include<stdio.h>
//#include<conio.h>
void quick_sort(int arr[] , int first , int last);
int partition(int arr[] , int first , int last);
void display_arr(int arr[] , int n);
void main(){
int i,n;
int arr[50];
//clrscr();
printf("Enter the number of elements ");
scanf("%d",&n);
printf("Enter the elements of the array \n");
for(i =0; i<n; i++){
scanf("%d",&arr[i]);}
quick_sort(arr,0,n-1);
printf("Elements after sorting ");
display_arr(arr,n);
//getch();
}
void display_arr(int arr[] , int n){
int i;
for(i =0; i<n; i++){
printf("%d ",arr[i]);}
}
void quick_sort(int arr[] , int first , int last){
int pindex;
if(first<last){
pindex = partition(arr,first,last);
quick_sort(arr,first, pindex - 1);
quick_sort(arr,pindex + 1 , last);
}}
int partition(int arr[] , int first , int last){
int pivot,i,j,temp;
pivot = arr[first];
i = first;
j =last;
while(i<j){
while(arr[i]<=pivot && i<last){
i++;}
while(arr[j]>pivot && j>first){
j--;}
if(i<j){
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
} }
temp = arr[first];
arr[first] = arr[j];
arr[j] = temp;
return j;
}
// result : quick sort is implemented and given list of array is sorted 