#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define V 3
#define INF 999999

void prims(int graph[V][V], int node){
  bool selected[V];
  int cost = 0;
  for(int k = 0; k < V; ++k){
    selected[k] = false;
  }
  selected[node] = true;
  printf("Path is - \n");
  for(int n = 0; n < V - 1; ++n){
    int elem = 0, root = 0, min = INF;
    for(int i = 0; i < V; ++i){
      if(selected[i] == true){
        for(int j = 0; j < V; ++j){
          if(graph[i][j] != 0 && min > graph[i][j] && selected[j] == false){
            min = graph[i][j];
            root = i;
            elem = j;
          }
        }
      }
    }
    cost += min;
    printf(" %d -> %d\t",root,elem);
    selected[elem] = true;
  }
  printf("\nMin cost is - %d",cost);
}


void printgraph(int graph[V][V]){
    for (int i = 0; i < V; ++i){
        for (int j = 0; j < V; ++j){
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }  
}

int main() {
  clock_t begin,end;
  int graph[V][V];
  for (int i = 0; i < V; ++i){
    for (int j = 0; j < V; ++j){
        printf("Enter Adjacency Matrix elements 0 or cost %d%d - ",i,j);
        scanf("%d",&graph[i][j]);
    }
  }
  printgraph(graph);
  printf("\n\n");
  int s;
  printf("Among 0,1,2,3,4 which node to start form - ");
  scanf("%d",&s);
  begin = clock();
  prims(graph,s);
  end = clock();
  double time = (double) (end - begin) / CLOCKS_PER_SEC;
  printf("Time Required Is - \n%f s",time);
}