#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Number of vertices in the graph

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

// Function to add a vertex to the queue (for BFS)
void enqueue(int v) {
    if (rear == MAX - 1) { // Basic overflow check
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Function to remove a vertex from the queue (for BFS)
int dequeue() {
    if (front == -1 || front > rear) { // Basic underflow check
        return -1;
    }
    return queue[front++];
}

// BFS function
void BFS(int adj[MAX][MAX], int start) {
    int visited[MAX] = {0}; // Array to keep track of visited vertices. 0 = not visited.
    enqueue(start); // Start by adding the starting vertex to the queue.
    visited[start] = 1; // Mark it as visited.
    printf("BFS Traversal: ");

    while (front <= rear) { // While the queue is not empty...
        int v = dequeue(); // ...remove a vertex from the front.
        printf("%d ", v); // ...and print it.

        for (int i = 0; i < MAX; i++) { // Then, explore its neighbors.
            // If there's an edge from 'v' to 'i' and 'i' has not been visited yet...
            if (adj[v][i] && !visited[i]) {
                enqueue(i); // ...add the neighbor to the queue.
                visited[i] = 1; // ...and mark it as visited.
            }
        }
    }
    printf("\n");
}

// Recursive utility function for DFS
void DFSUtil(int adj[MAX][MAX], int v, int visited[]) {
    visited[v] = 1; // Mark the current vertex as visited.
    printf("%d ", v); // Print it.

    for (int i = 0; i < MAX; i++) { // Explore its neighbors.
        // If there is an edge from 'v' to 'i' and 'i' has not been visited...
        if (adj[v][i] && !visited[i]) {
            DFSUtil(adj, i, visited); // ...recursively call DFS for that neighbor.
        }
    }
}

// DFS function
void DFS(int adj[MAX][MAX], int start) {
    int visited[MAX] = {0}; // Array to keep track of visited vertices.
    printf("DFS Traversal: ");
    DFSUtil(adj, start, visited); // Call the recursive helper function to start the traversal.
    printf("\n");
}

int main() {
    // Adjacency matrix representation of a directed graph.
    // adj[i][j] = 1 means there is an edge from vertex 'i' to vertex 'j'.
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},  // Edges from vertex 0: to 1, to 2
        {0, 0, 0, 1, 0},  // Edges from vertex 1: to 3
        {0, 0, 0, 1, 1},  // Edges from vertex 2: to 3, to 4
        {0, 0, 0, 0, 1},  // Edges from vertex 3: to 4
        {0, 0, 0, 0, 0}   // Edges from vertex 4: (none)
    };

    int start = 0; // The starting vertex for our traversals.

    BFS(adj, start); // Perform Breadth-First Search.
    DFS(adj, start); // Perform Depth-First Search.

    return 0;
}
