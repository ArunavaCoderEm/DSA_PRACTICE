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

// Comment out every sort except one in 'main' to perform that particular sort 

// Function Declaration
// BUBBLE SORT
void Bubble_Sort (int arr[], int size){
    int i,j,temp;
    for (i = 0; i < size; ++i){
        for (j = (i+1); j < size; ++j){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Or We Can Do The Swapping With Function We Can Use It Further
void swapG (int a,int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
//
void Bubble_Sorting (int arr[], int size){
    int i,j,temp;
    for (i = 0; i < size; ++i){
        for (j = (i+1); j < size; ++j){
            if (arr[i] > arr[j]){
                swapG(arr[i],arr[j]);
            }
        }
    }
}
// RECURSIVE MERGE SORT
void merge (int arr[], int low, int mid, int high){
    int i = low, j = mid + 1, k = low, A[high + 1];
    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            A[k] = arr[i];
            i++;
            k++;
        }
        else {
            A[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        A[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high){
        A[k] = arr[j];
        j++;
        k++;
    }
    for (int t = low; t <= high; ++t){
        arr[t] = A[t];
    }
}

void Merge_sort (int arr[], int lows, int highs){
    if (lows < highs){
        int mids = (lows + highs) / 2;
        Merge_sort(arr,lows,mids);
        Merge_sort(arr,mids + 1,highs);
        merge(arr,lows,mids,highs);
    }
}
//

void selection_sort(int arr[], int n){
    int i,j,min;
    for (i = 0; i < n - 1; ++i){
        min = i;
        for(j = i+1; j < n; ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
//

// MAIN FUNCTION

int main() {
    int i,j,n,arr[100],k;
    printf("How Many Elements In Array ? - ");
    scanf("%d",&n);
    for (i = 0; i < n; ++i){
        printf("Enter Element %d\n",i+1);
        scanf("%d",&arr[i]);
    }   
    printf("\nUnsorted Array Is -\n");
    for (j = 0; j < n; ++j){
        printf(" %d ",arr[j]);
    }   
    printf("\nSorting ...\n");
    Bubble_Sort(arr,n);
    printf("\nBubble Sorted Array Is -\n");
    for (k = 0; k < n; ++k){
        printf(" %d ",arr[k]);
    }      
    printf("\nSorting Again ...\n");
    Bubble_Sorting(arr,n);
    printf("\nBubble Sorted Array Again Is -\n");
    for (k = 0; k < n; ++k){
        printf(" %d ",arr[k]);
    }      
    printf("\nSorting Again ...\n");
    Merge_sort(arr,0,n-1);
    printf("\nMerge Sorted Array Is -\n");
    for (k = 0; k < n; ++k){
        printf(" %d ",arr[k]);
    }  
    printf("\nSorting Again ...\n");
    selection_sort(arr,0,n-1);
    printf("\selection Sorted Array Is -\n");
    for (k = 0; k < n; ++k){
        printf(" %d ",arr[k]);
    }  
    return(0);
}
