// aim : write a c program to implement merge sort 
// description :  it is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array. Merge Sort average time complexity is O (n log n)
#include<stdio.h>
//#include<conio.h>
void merge_sort(int arr[] , int first , int last);
void merge(int arr[] , int first , int mid , int last);
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
merge_sort(arr,0,n-1);
printf("Elements after sorting ");
display_arr(arr,n);
//getch();
}
void merge_sort(int arr[],int first ,int last){
int mid;
if(first>=last){
return;}
mid = (first + last )/2;
merge_sort(arr,first,mid);
merge_sort(arr,mid + 1,last);
merge(arr,first,mid,last);
}
void merge(int arr[] , int first , int mid , int last ){
int left,right,i;
int temp[100];
int ptr = 0;
left = first;
right = mid + 1;
while(left<=mid && right<=last){
if(arr[left]<arr[right]){
temp[ptr] = arr[left];
left++;
ptr++;
}
else{
temp[ptr] = arr[right];
right++;
ptr++;
}}
while(left<=mid){
temp[ptr] = arr[left];
ptr++;
left++;}
while(right<=last){
temp[ptr] = arr[right];
ptr++;
right++;}
for(i = 0; i<=last; i++){
arr[i + first] = temp[i];}
}
void display_arr(int arr[] , int n){
int i;
for(i = 0; i<n; i++){
printf("%d ",arr[i]);
}}
// result : Merge sort is implemented and given list of array is sorted 