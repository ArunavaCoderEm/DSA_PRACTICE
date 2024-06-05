#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
// fractional greedy

void swap(double * a, double * b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

void sortpro (double val[], double wt[], int n){
    double vbi[n];
    for(int i = 0; i < n; ++i){
        vbi[i] = val[i] / wt[i];
    }
    for(int j = 0; j < n-1; ++j){
        for(int k = j+1; k < n; ++k){
            if(vbi[k] > vbi[j]){
                swap(&vbi[j],&vbi[k]);
                swap(&val[j],&val[k]);
                swap(&wt[j],&wt[k]);
            }
        }
    }
}

double frac(int W, double wt[], double val[], int n){
    
    double to = 0.0;
    double curr = 0.0;
    sortpro(val,wt,n);
    for(int i = 0; i < n; ++i){
        if(curr + wt[i] < W){
            to += val[i];
            curr += wt[i];
        }
        else{
            double rem = W - curr; 
            double re = val[i] * (rem/wt[i]);
            to += (re);
            break;
        }
    }
    
    return to;  
}



// Recursive approach
int knapsack(int W, int wt[], int val[], int n){
    if(n == 0 || W == 0) return 0;
    if(wt[n-1] > W) return knapsack(W,wt,val,n-1);
    else return max(val[n-1] + knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
}

// dynamic programming approach
int knap01(int W, int wt[], int val[], int n) {
    int dyp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dyp[i][w] = 0;
            else if (wt[i-1] <= w)
                dyp[i][w] = max(val[i-1] + dyp[i-1][w-wt[i-1]], dyp[i-1][w]);
            else
                dyp[i][w] = dyp[i-1][w];
        }
    } 
    return dyp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 30, 20};
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    printf("Maximum value that can be obtained: %d\n", knap01(W, wt, val, n));
    return 0;
}
