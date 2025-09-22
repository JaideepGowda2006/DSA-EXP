#include <stdio.h>
#define MAX 5

int main() {
    int stack[MAX];
    int top = -1;
    int value = 13;

    // ---- PUSH OPERATION ----
    for (int i = 0; i < MAX; i++) {
        // Step 1: Check for overflow
        if (top == MAX - 1) {
            printf("OVERFLOW\n");
            break; // Step 4: End
        }

        // Step 2: Increment TOP
        top = top + 1;

        // Step 3: Insert VALUE
        stack[top] = value;
        printf("%d pushed\n", value);

        value = value + 13; // next multiple of 13
    }

    printf("\nStack after PUSH:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }

    // ---- POP OPERATION ----
    printf("\n\nPopping 2 elements...\n");
    for (int i = 0; i < 2; i++) {
        if (top == -1) {
            printf("UNDERFLOW\n");
            break;
        }
        printf("Popped: %d\n", stack[top]);
        top = top - 1;
    }

    printf("\nStack after POP:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }

    return 0;
}

