// Write a c program to implement 0/1 knapsack 
// description : The task of 0/1 knapsack is to put the item in the bag in such a way that sum of profit associated with them is maximum possible (we are not allowed to put part of an item )
#include <stdio.h>
    int weight[50], values[50],i,w,n,W,max_value;

int knapsack(int W, int weight[], int values[], int n) {
    int dp[n+1][W+1];


    for ( i = 0; i <= n; i++) {
        for ( w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  
            } else if (weight[i-1] <= w) {
                
                dp[i][w] = max(values[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][w]);
            } else {
               
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];  
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of knapsack: ");
    scanf("%d", &W);
    
    printf("\nEnter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    printf("\nEnter the values of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
     max_value = knapsack(W, weight, values, n);
    printf("The maximum value that can be obtained is: %d\n", max_value);
    
    return 0;
}

//result : Maximum profit was calculated by 0/1 knapsack via dynamic programming 