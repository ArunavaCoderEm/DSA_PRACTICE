#include <stdio.h>
#include <stdbool.h>

#define V 100

struct Queue {
    int front, rear;
    int items[V];
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue *q) {
    return q->rear == -1;
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == V - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

void BFS(int graph[V][V], int vertices, int start) {
    struct Queue q;
    bool visited[V] = {false};

    initQueue(&q);
    visited[start] = true;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int vertices = 6;

    printf("BFS Traversal starting from node 0: ");
    BFS(graph, vertices, 0);
    printf("\n");

    return 0;
}
