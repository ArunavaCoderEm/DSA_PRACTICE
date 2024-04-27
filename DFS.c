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

#define V 5

int vis[V] = {0,0,0,0,0}; // do with a loop in exam v = 0 -> v < V

void dfs (int graph[V][V], int start, int n){
    printf(" %d -> ",start);
    vis[start] = 1;
    for (int i = 0; i < n; ++i){
        if(graph[start][i] == 1 && !vis[i]) dfs(graph,i,n);
    }
}

// MAIN FUNCTION

int main() {
    int graph[V][V] = { // do user ip in exam with function
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0},
    };
    dfs(graph,1,V);
    return(0);
}
