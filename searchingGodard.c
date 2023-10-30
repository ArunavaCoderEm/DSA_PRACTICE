// // Linear Search
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

// Function Declaration
int linear_search (int arr[], int s , int key){
    for (int i = 0; i < s; ++ i){
        if (key == arr[i]){
            return (i);
        }
    }
    return (-1);
}


// MAIN FUNCTION

int main() {
    int i,j,n,arr[100],k,m = 1;
    printf("How Many Elements In Array ? - ");
    scanf("%d",&n);
    for (i = 0; i < n; ++i){
        printf("Enter Element %d\n",i+1);
        scanf("%d",&arr[i]);
    }   
    printf("\nArray is -\n");
    for (j = 0; j < n; ++j){
        printf(" %d ",arr[j]);
    }
    printf("\nLinear Searching ...\n");
    while (m != 0) {
        printf("\nEnter Element You Want To Search - \n");
        scanf("%d",&k);
        if (linear_search(arr,n,k) >= 0){
            printf("\n%d Found At %d Index\n",k,linear_search(arr,n,k));
        }
        else {
            printf("\n%d Not Found\n",k);
        }
        printf("\n Search Again ? - (0 / 1) -- ");
        scanf("%d",&m);
    }
    printf("\nOkay GoodBye !\n");
    return(0);
}

// // Binary Search // Acts On Sorted Array So We Will Sort It First (Bubble Sort)
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

// Function Declaration
void Bubble_Sort (int arr[], int size){
    int i,j,temp;
    for (i = 0; i < size; ++i){
        for (j = i+1; j < size; ++j){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int Binary_search(int array[], int key, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] == key){
      return mid;
    }
    if (array[mid] < key){
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return -1;
}

// MAIN FUNCTION

int main() {
    int i,j,n,arr[100],k, m =1,key;
    printf("How Many Elements In Array ? - ");
    scanf("%d",&n);
    for (i = 0; i < n; ++i){
        printf("Enter Element %d\n",i+1);
        scanf("%d",&arr[i]);
    }   
    printf("\nUnsorted Array is -\n");
    for (j = 0; j < n; ++j){
        printf(" %d ",arr[j]);
    }   
    printf("\nSorting ...\n");
    Bubble_Sort(arr,n);
    printf("\nSorted Array is -\n");
    for (k = 0; k < n; ++k){
        printf(" %d ",arr[k]);
    }  
    int low = 0, high = n-1;
    while (m != 0){
        printf("\nElement You Want To Search - \n");
        scanf("%d",&key);
        if (Binary_search(arr,key,low,high) >= 0){
            printf("\n%d Found At %d Index\n",key,Binary_search(arr,key,low,high));
        }
        else {
            printf("\n%d Not Found\n",key);
        }
        printf("\nSearch Again ? - (0/1) - \n");
        scanf("%d",&m);
    }
    return(0);
}
