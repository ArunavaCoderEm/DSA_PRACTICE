#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6

int mindist(int dist[V], bool vis[V]) {
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; ++v){
        if(vis[v] == false && dist[v] < min){
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printsoln(int dist[V]){
    printf("Vertex Node \t\t Distance From Source 0");
    for(int i = 0; i < V; ++i){
        printf("\n %d \t\t\t %d",i,dist[i]);
    }
}

void dijkstra (int graph[V][V], int node){
    int dist[V];
    bool vis[V];
    for(int k = 0; k < V; ++k){
        vis[k] = false;
        dist[k] = INT_MAX;
    }
    dist[node] = 0;
    for (int n = 0; n < V; ++n){
        int u = mindist(dist,vis);
        vis[u] = true;
        if (u == INT_MAX){
            continue;
        }
        for (int v = 0; v < V; ++v){
            if(dist[u] + graph[u][v] < dist[v] && vis[v] == false && graph[u][v] != 0){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    } 
    printsoln(dist);
}

int main(){	
	int graph[V][V] = { { 0, 7, 9, 0, 0, 14 },
						{ 7, 0, 10, 15, 0, 0},
						{ 9, 10, 0, 11, 0, 2},
						{ 0, 15, 11, 0, 6, 0},
						{ 0,  0, 0,  6, 0, 9},
						{ 14, 0, 2,  0, 9, 0},
					};	
	dijkstra(graph, 0);
	return 0;
}
