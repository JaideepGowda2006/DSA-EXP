#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Number of vertices

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// BFS function
void BFS(int adj[MAX][MAX], int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < MAX; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS function
void DFSUtil(int adj[MAX][MAX], int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < MAX; i++) {
        if (adj[v][i] && !visited[i]) {
            DFSUtil(adj, i, visited);
        }
    }
}

void DFS(int adj[MAX][MAX], int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFSUtil(adj, start, visited);
    printf("\n");
}

int main() {
    // Example directed graph adjacency matrix
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},  // edges from vertex 0
        {0, 0, 0, 1, 0},  // edges from vertex 1
        {0, 0, 0, 1, 1},  // edges from vertex 2
        {0, 0, 0, 0, 1},  // edges from vertex 3
        {0, 0, 0, 0, 0}   // edges from vertex 4
    };

    int start = 0;

    BFS(adj, start);
    DFS(adj, start);

    return 0;
}

