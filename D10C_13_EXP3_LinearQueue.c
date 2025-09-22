#include <stdio.h>
#define MAX 5

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int value = 13; // start with first multiple of 13

    // ---- ENQUEUE (Insert multiples of 13) ----
    for (int i = 0; i < MAX; i++) {
        if (rear == MAX - 1) {
            printf("Queue Overflow\n");
            break;
        }
        if (front == -1) front = 0; // first element
        queue[++rear] = value;
        printf("%d enqueued\n", value);
        value += 13; // next multiple
    }

    // Display queue after enqueue
    printf("\nQueue after enqueue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    // ---- DEQUEUE (Delete 2 elements) ----
    printf("\n\nDequeuing two elements...\n");
    for (int i = 0; i < 2; i++) {
        if (front == -1 || front > rear) {
            printf("Queue Underflow\n");
            break;
        }
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }

    // Display queue after dequeue
    if (front == -1 || front > rear) {
        printf("\nQueue is empty now.\n");
    } else {
        printf("\nQueue after dequeue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    return 0;
}

