#include <stdio.h>
#include <stdbool.h>

#define N 4  

void printPath(int path[], int pathLen) {
  for (int i = 0; i < pathLen; i++) {
    printf("%d ", path[i]);
  }
  printf("\n");
}

bool isSafe(bool vis[], int v, int path[], int pathLen) {
  for (int i = 0; i < pathLen; i++) {
    if (path[i] == v) {
      return false;
    }
  }
  return true;
}

bool hamUtil(int graph[N][N], bool vis[], int path[], int pathLen, int v) {
  if (pathLen == N) {
    if (graph[path[pathLen - 1]][v] == 1) {
      printPath(path, pathLen);
      return true;
    } else {
      return false;
    }
  }
  for (int i = 0; i < N; i++) {
    if (graph[v][i] == 1 && isSafe(vis, i, path, pathLen)) {
      vis[i] = true;
      path[pathLen] = i;
      if (hamUtil(graph, vis, path, pathLen + 1, i)) {
        return true;
      }
      vis[i] = false;
    }
  }
  return false;
}

void printAllHamiltonianCycles(int graph[N][N]) {
  bool vis[N];  
  int path[N];  
  for (int i = 0; i < N; i++) {
    vis[i] = false;
  }
  path[0] = 0;
  vis[0] = true;
  if (!hamUtil(graph, vis, path, 1, 0)) {
    printf("No Hamiltonian Cycle found !!\n");
  }
}

int main() {
  int graph[N][N] = {{1, 1, 0, 1}, {1, 1, 0, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}};
  printf("All Hamiltonian Cycles:\n");
  printAllHamiltonianCycles(graph);
  return 0;
}
