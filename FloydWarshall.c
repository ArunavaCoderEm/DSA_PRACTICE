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
#define INF INT_MAX 
#define V 4

// Function Declaration

void printgraph(int d[V][V]){
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(d[i][j] == INF){
                printf(" INF ");
            }
            else printf(" %d ",d[i][j]);
        }
    printf("\n");
    }
}

void floydwarshall(int graph[V][V]){
    int dis[V][V];
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            dis[i][j] = graph[i][j];
        }
    }
    for(int k = 0; k < V; ++k){
        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j){
                if(dis[i][j] > dis[i][k] + dis[k][j] && dis[i][k] != INF && dis[k][j] != INF){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    printgraph(dis);
}


// MAIN FUNCTION

int main() {
    int graph[V][V] = {
        {0,3,INF,7},
        {INF,0,4,1},
        {1,INF,0,5},
        {INF,INF,3,0}
    };
    floydwarshall(graph);
    return(0);
}
