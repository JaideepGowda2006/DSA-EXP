#include <stdio.h>

#define SIZE 5

// Utility function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    // This algorithm works by repeatedly finding the minimum element from the unsorted part
    // and putting it at the beginning.
    for (int i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted array arr[i..n-1]
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        // Swap the found minimum element with the first element of the unsorted part.
        swap(&arr[i], &arr[min_idx]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    // This algorithm repeatedly steps through the list, compares adjacent elements,
    // and swaps them if they are in the wrong order. The largest elements "bubble" to the top.
    for (int i = 0; i < n-1; i++) { // The outer loop controls the number of passes.
        for (int j = 0; j < n-i-1; j++) { // The inner loop performs the comparisons.
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    // This algorithm builds the final sorted array one item at a time.
    // It iterates through the input elements and inserts each element into its correct position
    // in the sorted part of the array.
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Pick the element to be inserted.
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position.
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; // Place the key in its correct sorted position.
    }
}

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE] = {13, 39, 26, 65, 52};
    int choice;

    do {
        // A menu-driven interface to let the user choose a sorting algorithm.
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                selectionSort(arr, SIZE);
                printf("Array sorted using Selection Sort.\n");
                break;
            case 2:
                bubbleSort(arr, SIZE);
                printf("Array sorted using Bubble Sort.\n");
                break;
            case 3:
                insertionSort(arr, SIZE);
                printf("Array sorted using Insertion Sort.\n");
                break;
            case 4:
                printf("Array: ");
                display(arr, SIZE);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
