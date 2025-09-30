#include <stdio.h>
#define MAX 5

int main() {
    int queue[MAX];
    // The array to store queue elements.
    int front = -1, rear = -1;
    // 'front' points to the first element, 'rear' points to the last. -1 indicates an empty queue.
    int value = 13;

    // ---- ENQUEUE (Insert multiples of 13) ----
    printf("---- ENQUEUE ----\n");
    for (int i = 0; i < MAX; i++) {
        if (rear == MAX - 1) {
            // If 'rear' is at the last index, the queue is full.
            printf("Queue Overflow\n");
            break;
        }
        if (front == -1) front = 0; // If it's the first element, set 'front' to 0.
        queue[++rear] = value;
        // Increment 'rear' and then insert the value.
        printf("%d enqueued\n", value);
        value += 13;
    }

    // Display queue after enqueue
    printf("\nQueue after enqueue:\n");
    for (int i = front; i <= rear; i++) {
        // Loop from 'front' to 'rear' to print elements.
        printf("%d ", queue[i]);
    }
    printf("\n");

    // ---- DEQUEUE (Delete 2 elements) ----
    printf("\n\n---- DEQUEUE ----\n");
    printf("Dequeuing two elements...\n");
    for (int i = 0; i < 2; i++) {
        if (front == -1 || front > rear) {
            // If 'front' is -1 or has passed 'rear', the queue is empty.
            printf("Queue Underflow\n");
            break;
        }
        printf("Dequeued: %d\n", queue[front]);
        // Print the element at the 'front'.
        front++;
        // Increment 'front' to "remove" the element.
    }

    // Display queue after dequeue
    if (front == -1 || front > rear) {
        // Check if the queue became empty after dequeuing.
        printf("\nQueue is empty now.\n");
    } else {
        printf("\nQueue after dequeue:\n");
        for (int i = front; i <= rear; i++) {
            // Print the remaining elements.
            printf("%d ", queue[i]);
        }
        printf("\n");
    }

    return 0;
}
