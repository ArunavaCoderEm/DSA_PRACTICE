#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3

void printPuzzle(int puzzle[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMin(int a, int b, int c, int d) {
    int min = a;
    min = (b < min) ? b : min;
    min = (c < min) ? c : min;
    min = (d < min) ? d : min;
    return min;
}

int calcMisplaced(int puzzle[N][N]){
    int misplaced = 0 ;
    for(int i = 0 ; i<N ; i++){
        for(int j = 0 ; j<N ; j++){
            if (puzzle[i][j] != 0 && puzzle[i][j] != N*i + j + 1) {
                misplaced++;
            }
        }
    }
    return misplaced ;
}

bool isSolvable(int puzzle[N][N]) {
    int inversions = 0;
    int arr[N*N];
    int k = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            arr[k++] = puzzle[i][j];
        }
    }
    for(int i = 0; i < N*N - 1; i++) {
        for(int j = i + 1; j < N*N; j++) {
            if(arr[i] && arr[j] && arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    if (N % 2 == 1) {
        return inversions % 2 == 0;
    }
    else {
        int pos;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (puzzle[i][j] == 0) {
                    pos = i;
                }
            }
        }
        if (pos % 2 == 0) {
            return inversions % 2 == 1;
        }
        else {
            return inversions % 2 == 0;
        }
    }
}

void solvePuzzle(int puzzle[N][N]) {
    if (!isSolvable(puzzle)) {
        printf("The puzzle is not solvable.\n");
        return;
    }
    int res = calcMisplaced(puzzle);
    if(res==0){
        printf("\nGoal State Achieved\n");
        return;
    }
    int i ,j;
    for(int row = 0 ; row<N ; row++){
        for(int col=0 ; col<N; col++){
            if(puzzle[row][col]==0){
                i=row ;
                j = col ;
                break ;
            }
        }
    }
    int misplacedLeft = 10;
    int misplacedRight = 10;
    int misplacedUp = 10;
    int misplacedDown= 10;

    //left move 
    if(j-1>=0){
        swap(&puzzle[i][j], &puzzle[i][j-1]);
        misplacedLeft = calcMisplaced(puzzle);
        swap(&puzzle[i][j], &puzzle[i][j-1]);
    }
    //right move 
    if(j+1<N){
        swap(&puzzle[i][j], &puzzle[i][j+1]);
        misplacedRight = calcMisplaced(puzzle);
        swap(&puzzle[i][j], &puzzle[i][j+1]);
    }
    //up move 
    if(i-1>=0){
        swap(&puzzle[i][j], &puzzle[i-1][j]);
        misplacedUp = calcMisplaced(puzzle);
        swap(&puzzle[i][j], &puzzle[i-1][j]);
    } 
    //down move 
    if(i+1<N){
        swap(&puzzle[i][j], &puzzle[i+1][j]);
        misplacedDown = calcMisplaced(puzzle);
        swap(&puzzle[i][j], &puzzle[i+1][j]);
    }
    
    int minimum = findMin(misplacedDown,misplacedLeft,misplacedRight,misplacedUp);

    if(minimum == misplacedLeft){
        swap(&puzzle[i][j], &puzzle[i][j-1]);
        printf("\nMove blank to left\n");
        printPuzzle(puzzle);
        solvePuzzle(puzzle);
    }
    else if(minimum == misplacedRight){
        swap(&puzzle[i][j], &puzzle[i][j+1]);
        printf("\nMove blank to right\n");
        printPuzzle(puzzle);
        solvePuzzle(puzzle);
    }
    else if(minimum == misplacedUp){
        swap(&puzzle[i][j], &puzzle[i-1][j]);
        printf("\nMove blank to up\n");
        printPuzzle(puzzle);
        solvePuzzle(puzzle);
    }
    else if(minimum == misplacedDown){
        swap(&puzzle[i][j], &puzzle[i+1][j]);
        printf("\nMove blank to down\n");
        printPuzzle(puzzle);
        solvePuzzle(puzzle);
    }

}

int main() {
    int puzzle[N][N] = {
        {1, 2, 3},
        {0, 4, 5},
        {7, 8, 6} 
    };
    printf("\nInitial State of the puzzle\n");
    printPuzzle(puzzle);
    solvePuzzle(puzzle);

    return 0;
}

