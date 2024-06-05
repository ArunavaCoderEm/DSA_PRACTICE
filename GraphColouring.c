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
#define V 4
#define C 3

// Function Declaration


void printsol(int col[V]){
    for(int i = 0; i < V; ++i){
        printf("Vertex %d  -> colour %d \n",i,col[i]);
    }
}

bool iscolsafe(int g[V][V], int col[V], int v, int c){
    for(int i = 0; i < V; ++i){
        if(g[v][i] && col[i] == c) return false;
    }
    return true;
} 

bool colutil(int g[V][V], int m, int v, int col[V]){
    if(v == V){
        printsol(col);
        return true;
    }
    for(int c = 1; c < m; ++c){
        if(iscolsafe(g,col,v,c)){
            col[v] = c;
        }
        if(colutil(g,m,v+1,col)){
            return true;
        }
        col[v] = 0;
    }
    return false;
}

bool gcolor(int g[V][V], int m){
    int col[V];
    for(int i = 0; i < V; ++i){
        col[i] = 0;
    }
    if(!colutil(g,m,0,col)){
        printf("There's no solution exists\n");
        return false;
    }
    return true;
}


// MAIN FUNCTION

int main() {
    int g[V][V] = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int m = C;
    gcolor(g,m);
    return(0);
}
