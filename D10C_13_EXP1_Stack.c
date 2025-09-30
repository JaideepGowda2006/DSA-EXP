#include <stdio.h>
// Includes the standard input/output library for functions like printf().

#define MAX 5
// Defines a constant 'MAX' with a value of 5. This is the maximum size of our stack.

int main() {
    int stack[MAX];
    // Declares an integer array named 'stack' of size MAX (5). This array will store our stack elements.

    int top = -1;
    // Declares an integer 'top' and initializes it to -1. 'top' keeps track of the index of the last element added to the stack. -1 means the stack is initially empty.

    int value = 13;
    // Initializes a variable 'value' to 13. We'll use this to push multiples of 13 onto the stack.

    // ---- PUSH OPERATION ----
    printf("---- PUSH OPERATION ----\n");
    for (int i = 0; i < MAX; i++) {
        // A loop to push 5 elements onto the stack.

        // Step 1: Check for overflow
        if (top == MAX - 1) {
            // Checks if 'top' is at the last index (5 - 1 = 4). If it is, the stack is full.
            printf("OVERFLOW\n");
            // Prints an overflow message.
            break; // Step 4: End
            // Exits the loop because we can't add any more elements.
        }

        // Step 2: Increment TOP
        top = top + 1;
        // Increments 'top' to point to the next empty space. For the first element, top becomes 0.

        // Step 3: Insert VALUE
        stack[top] = value;
        // Assigns the 'value' to the stack at the new 'top' index.
        printf("%d pushed\n", value);
        // Prints which value was pushed.

        value = value + 13; // next multiple of 13
        // Updates 'value' to the next multiple of 13 for the next iteration.
    }

    printf("\nStack after PUSH:\n");
    for (int i = 0; i <= top; i++) {
        // A loop from the bottom (index 0) to the top of the stack.
        printf("%d ", stack[i]);
        // Prints each element to show the final state of the stack.
    }
    printf("\n");

    // ---- POP OPERATION ----
    printf("\n\n---- POP OPERATION ----\n");
    printf("Popping 2 elements...\n");
    for (int i = 0; i < 2; i++) {
        // A loop to pop 2 elements from the stack.

        // Step 1: Check for underflow
        if (top == -1) {
            // Checks if the stack is empty. If 'top' is -1, there's nothing to pop.
            printf("UNDERFLOW\n");
            // Prints an underflow message.
            break;
            // Exits the loop.
        }
        
        // Step 2: Access and print the top element
        printf("Popped: %d\n", stack[top]);
        // Prints the element at the top of the stack, which is about to be removed.

        // Step 3: Decrement TOP
        top = top - 1;
        // Decrements 'top', effectively "removing" the last element. The value is still in the array, but it's now inaccessible and will be overwritten by the next push.
    }

    printf("\nStack after POP:\n");
    for (int i = 0; i <= top; i++) {
        // Another loop to display the stack's current state.
        printf("%d ", stack[i]);
        // Prints the remaining elements.
    }
    printf("\n");

    return 0;
    // Indicates successful program execution.
}
