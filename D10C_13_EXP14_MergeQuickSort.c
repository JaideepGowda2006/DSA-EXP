#include <stdio.h>

#define SIZE 6

// Utility function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merge function for Merge Sort
// This function merges two sorted subarrays: arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // Size of the left subarray.
    int n2 = r - m;     // Size of the right subarray.

    int L[n1], R[n2]; // Create temporary arrays.

    // Copy data to temporary arrays L[] and R[].
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l; // Initial indexes for left, right, and merged subarrays.

    // Merge the temp arrays back into arr[l..r].
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++]; // Pick the smaller element from L.
        else
            arr[k++] = R[j++]; // Pick the smaller element from R.
    }

    // Copy any remaining elements of L[] and R[].
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort function (main recursive function)
void mergeSort(int arr[], int l, int r) {
    if (l < r) { // Base case: if l >= r, the subarray has 0 or 1 elements, which is already sorted.
        int m = l + (r - l)/2; // Find the middle point to divide the array.
        mergeSort(arr, l, m);      // Recursively sort the first half.
        mergeSort(arr, m+1, r);    // Recursively sort the second half.
        merge(arr, l, m, r);       // Merge the two sorted halves.
    }
}

// Partition function for Quick Sort
// This function takes the last element as a pivot, places it at its correct sorted position,
// and puts all smaller elements to its left and all greater elements to its right.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot.
    int i = low - 1;       // Index of the smaller element.

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]); // Place the pivot in its correct position.
    return i + 1; // Return the index of the pivot.
}

// Quick Sort function (main recursive function)
void quickSort(int arr[], int low, int high) {
    if (low < high) { // Base case: subarray has more than one element.
        int pi = partition(arr, low, high); // 'pi' is the partitioning index.
        quickSort(arr, low, pi - 1);  // Recursively sort elements before the pivot.
        quickSort(arr, pi + 1, high); // Recursively sort elements after the pivot.
    }
}

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE] = {13, 39, 26, 65, 52, 78};
    int choice;

    do {
        // Menu-driven interface.
        printf("\nMenu:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                mergeSort(arr, 0, SIZE - 1);
                printf("Array sorted using Merge Sort.\n");
                break;
            case 2:
                quickSort(arr, 0, SIZE - 1);
                printf("Array sorted using Quick Sort.\n");
                break;
            case 3:
                printf("Array: ");
                display(arr, SIZE);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}
