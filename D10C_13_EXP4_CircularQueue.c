#include <stdio.h>
#define MAX 5

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int value = 13;

    // ---- ENQUEUE (Insert) ----
    printf("---- ENQUEUE ----\n");
    for (int i = 0; i < MAX; i++) {
        // check for overflow
        if ((rear + 1) % MAX == front) {
            // This is the key condition for a full circular queue. It checks if 'rear' is right behind 'front'.
            printf("Queue Overflow\n");
            break;
        }

        if (front == -1) front = 0; // On first insertion, set 'front' to 0.
        rear = (rear + 1) % MAX;
        // 'rear' is incremented circularly. For example, if rear is 4 and MAX is 5, (4+1)%5 becomes 0.
        queue[rear] = value;
        printf("%d enqueued\n", value);
        value += 13;
    }

    // Display queue
    printf("\nQueue after enqueue:\n");
    // The display logic is more complex because the elements might "wrap around" the end of the array.
    if (front <= rear) { // Normal case, no wrap around.
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else { // Wrap around case (front > rear).
        for (int i = front; i < MAX; i++) // Print from front to the end of the array.
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++) // Print from the beginning of the array to rear.
            printf("%d ", queue[i]);
    }

    // ---- DEQUEUE (Remove 2 elements) ----
    printf("\n\n---- DEQUEUE ----\n");
    printf("Dequeuing two elements...\n");
    for (int i = 0; i < 2; i++) {
        if (front == -1) { // Check for underflow.
            printf("Queue Underflow\n");
            break;
        }
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            // If only one element was in the queue, it's now empty.
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
            // 'front' is also incremented circularly.
        }
    }

    // Display queue after dequeue
    printf("\nQueue after dequeue:\n");
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (front <= rear) {
        // Use the same wrap-around logic for displaying.
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");

    return 0;
}
