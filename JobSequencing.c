// LIBRARIES INCLUDED
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// DEFINES
// Function Declaration

void swap(int * a, int * b){
    int temp = * a;
    * a = * b;
    * b = temp;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int findmax(int arr[], int n){
    int m = arr[0];
    for(int i = 1; i < n; ++i){
        m = max(m,arr[i]);
    }
    return m;
}

void sortjobprio(int profit[], int deadline[], int n){
    for(int  i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(profit[i] < profit[j]){
                swap(&profit[i], & profit[j]);
                swap(&deadline[i], & deadline[j]);
            }
        }
    }
}

int schedulejobs(int profit[], int deadline[], int n){
    int maxd = findmax(deadline, n);
    int slots[maxd];
    sortjobprio(profit,deadline,n);
    for(int i = 0; i < n; ++i) slots[i] = -1;
    int cou = 0, tot = 0;
    for(int j = 0; j < n; ++j){
        int d = deadline[j];
        for(int k = d - 1; k >= 0; k--){
            if(slots[k] == -1){
                slots[k] = j;
                cou++;
                tot += profit[j];
                break; 
            }
        }
    }
    printf("Total profit %d\n",tot);
    return cou;
}

// MAIN FUNCTION

int main() {
    int profit[] = {100, 19, 27, 25, 15};  
    int deadline[] = {2, 1, 4, 1, 3};    

    int n = sizeof(profit) / sizeof(profit[0]);  

    int max_profit = schedulejobs(profit, deadline, n);

    printf("Total profit earned by scheduling %d jobs\n", max_profit);

    return 0;
}
