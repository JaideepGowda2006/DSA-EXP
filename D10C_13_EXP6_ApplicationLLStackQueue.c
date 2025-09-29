nclude <stdio.h>  // Standard input-output library for functions like printf, scanf
#include <stdlib.h> // Standard library for general utilities, including memory allocation (malloc, free, exit)
#include <string.h> // String manipulation functions (e.g., strcpy)

// Node structure for the linked list. Each node represents a song.
struct Node {
    char song[50];     // Stores the name of the song (up to 49 characters + null terminator)
    struct Node* next; // Pointer to the next node in the stack (the previous song played)
};

// Global pointer to the top of the stack.
// 'top' always points to the most recently played song.
struct Node* top = NULL;

// Function to add a new song to the playlist (Push operation on the stack).
// This simulates playing a new song.
void push(char* songName) {
    // 1. Allocate memory for a new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return;
    }

    // 2. Copy the song name into the new node.
    strcpy(newNode->song, songName);

    // 3. Link the new node to the current top of the stack.
    //   The 'next' of the new song becomes the song that was previously at the top.
    newNode->next = top;

    // 4. Update 'top' to point to the new song, making it the current song.
    top = newNode;
    printf("Now playing: %s\n", songName);
}

// Function to go back to the previous song (Pop operation on the stack).
// This removes the current song from the top and makes the previous one current.
void pop() {
    // 1. Check if the playlist is empty (stack underflow).
    if (top == NULL) {
        printf("No previous song!\n");
        return; // Cannot pop from an empty stack
    }

    // 2. Announce which song is being stopped.
    printf("Stopping: %s\n", top->song);

    // 3. Create a temporary pointer to the current top node.
    struct Node* temp = top;

    // 4. Move the 'top' pointer to the next node, effectively making the previous song current.
    top = top->next;

    // 5. Free the memory of the old top node (the song that was stopped).
    free(temp);

    // 6. Announce the new current song, if any.
    if (top != NULL)
        printf("Now playing: %s\n", top->song);
    else
        printf("No song playing.\n"); // The playlist is now empty
}

// Function to show the current song (Peek operation on the stack).
// This looks at the top element without removing it.
void peek() {
    // 1. Check if there's any song playing.
    if (top == NULL) {
        printf("No song is playing.\n");
    } else {
        // 2. Display the song name at the top of the stack.
        printf("Currently playing: %s\n", top->song);
    }
}

// Function to display the entire playlist history (stack contents).
// Shows songs from most recent to oldest.
void display() {
    // 1. Check if the playlist is empty.
    if (top == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    // 2. Use a temporary pointer to traverse the stack from top to bottom.
    struct Node* temp = top;
    printf("Playlist history (latest first):\n");
    while (temp != NULL) {
        printf("%s -> ", temp->song); // Print the current song's name
        temp = temp->next;           // Move to the next (older) song
    }
    printf("NULL\n"); // Indicates the end of the playlist history
}

// Main function where the program execution begins.
int main() {
    int choice;    // Variable to store the user's menu choice
    char song[50]; // Buffer to store the song name entered by the user

    // Infinite loop for the music player menu.
    while (1) {
        // Display the menu options to the user.
        printf("\n--- Music Player Menu ---\n");
        printf("1. Play New Song (Push)\n");
        printf("2. Go Back to Previous Song (Pop)\n");
        printf("3. Show Current Song (Peek)\n");
        printf("4. Show Playlist History (Display)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice); // Read the user's integer choice

        // Use a switch statement to perform actions based on user's choice.
        switch (choice) {
            case 1:
                printf("Enter song name: ");
                // `scanf(" %[^\n]", song)`:
                //  - The leading space ` ` consumes any leftover newline characters from previous inputs.
                //  - `[^\n]` reads all characters until a newline is encountered.
                //  - This allows for multi-word song titles.
                scanf(" %[^\n]", song);
                push(song); // Call the push function to play the new song
                break;
            case 2:
                pop(); // Call the pop function to go back to the previous song
                break;
            case 3:
                peek(); // Call the peek function to show the current song
                break;
            case 4:
                display(); // Call the display function to show the playlist history
                break;
            case 5:
                exit(0); // Terminate the program cleanly
            default:
                printf("Invalid choice!\n"); // Handle invalid menu inputs
        }
    }
    return 0; // Should technically not be reached due to exit(0)
}
