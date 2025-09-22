#include <stdio.h>
#define MAX 5

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int value = 13; // start with first multiple of 13

    // ---- ENQUEUE (Insert) ----
    for (int i = 0; i < MAX; i++) {
        // check for overflow
        if ((rear + 1) % MAX == front) {
            printf("Queue Overflow\n");
            break;
        }

        if (front == -1) front = 0; // first element
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d enqueued\n", value);
        value += 13; // next multiple
    }

    // Display queue
    printf("\nQueue after enqueue:\n");
    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else { // wrap around case
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    // ---- DEQUEUE (Remove 2 elements) ----
    printf("\n\nDequeuing two elements...\n");
    for (int i = 0; i < 2; i++) {
        if (front == -1) {
            printf("Queue Underflow\n");
            break;
        }
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Display queue after dequeue
    printf("\nQueue after dequeue:\n");
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else { // wrap around case
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    return 0;
}

