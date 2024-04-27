#include <stdio.h>
#include <limits.h>

#define V 4 

int visited[V];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp (int graph[V][V], int current, int count){
    if(count == V) return graph[current][0];
    visited[current] = 1;
    int minc = INT_MAX;
    for (int i = 0; i < V; ++i){
        if(!visited[i]){
            int cost = graph[current][i] + tsp(graph,i,count + 1);
            minc = min(minc,cost);
        }
    }
    visited[current] = 0;
    return minc;
}

int main() {
    int graph[V][V]; 
    for (int i = 0; i < V; ++i){
      for (int j = 0; j < V; ++j){
        printf("Enter Adjacency Matrix elements 0 or cost %d%d - ",i,j);
        scanf("%d",&graph[i][j]);
    }
  }
    for (int i = 0; i < V; i++)
        visited[i] = 0; 
    int minCost = tsp(graph,0, 1); 
    printf("Minimum cost of the TSP : %d\n", minCost);
    return 0;
}