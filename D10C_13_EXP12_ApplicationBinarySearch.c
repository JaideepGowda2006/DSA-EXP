```c
#include <stdio.h>   // Standard input-output header file
#include <string.h>  // For using strcmp() to compare strings

// Function to perform Binary Search on a sorted list of songs
int binarySearch(char playlist[][50], int n, char song[]) {
    int low = 0;             // Start index
    int high = n - 1;        // End index

    // Loop continues until search space is valid
    while (low <= high) {
        int mid = (low + high) / 2;  // Middle index of current range

        // Compare target song with song at mid index
        int cmp = strcmp(song, playlist[mid]);

        if (cmp == 0) {
            return mid; // Song found → return its index
        } else if (cmp < 0) {
            // If target song is alphabetically smaller,
            // search in the left half
            high = mid - 1;
        } else {
            // If target song is alphabetically greater,
            // search in the right half
            low = mid + 1;
        }
    }
    return -1; // Song not found → return -1
}

int main() {
    int n;            // Number of songs in playlist
    char song[50];    // Song name to search

    // Step 1: Input the number of songs
    printf("Enter number of songs: ");
    scanf("%d", &n);

    // Step 2: Declare a 2D array to store 'n' songs (each max 50 characters)
    char playlist[n][50];

    // Step 3: Input the songs in alphabetical order (important for binary search)
    printf("Enter songs in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", playlist[i]);  // Read each song (no spaces allowed in name)
    }

    // Step 4: Input the song name to search
    printf("Enter song to search: ");
    scanf("%s", song);

    // Step 5: Call binarySearch function to find song
    int result = binarySearch(playlist, n, song);

    // Step 6: Display result based on return value
    if (result != -1)
        printf("Song '%s' found at position %d.\n", song, result + 1); // +1 for human-friendly position
    else
        printf("Song '%s' not found in playlist.\n", song);

    return 0;  // Program ends
}
```

