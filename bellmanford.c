
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 7

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void bellman(int graph[V][V], int src){
   int dist[V];
   bool vis[V];
   int flag = 0;
   for(int h = 0; h < V; ++h){
    for(int k = 0; k < V; ++k){
        dist[k] = INT_MAX;
        vis[k] = false;
    }
        dist[src] = 0;
        for(int i = 0; i < V; ++i){
            int u = minDistance(dist,vis);
            vis[u] = true;
            if(u == INT_MAX) continue;
            for(int v=0; v < V; ++v){
                if(dist[u] + graph[u][v] < dist[v] && graph[u][v] != 0 && vis[v] == false){
                    dist[v] = dist[u] + graph[u][v];
                    if(h > V - 1) flag = 1;
                }
            }
        }
        if(flag == 1) break;
    }
    printSolution(dist);
}

int main()
{
	int graph[V][V] = { { 0, 6, 5, 5, 0, 0, 0},
						{ 0, 0, 0, 0, -1, 0, 0},
						{ 0, -2, 0, 0, 1, 0, 0},
						{ 0, 0, -2, 0, 0, -1, 0},
						{ 0, 0, 0, 0, 0, 0, 3},
						{ 0, 0, 0, 0, 0, 0, 3},
                        { 0, 0, 0, 0, 0, 0, 0}
					};
	
	bellman(graph, 0);

	return 0;
}
