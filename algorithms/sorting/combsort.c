#include <stdio.h>
#include <stdbool.h>

// Function to update the gap by applying the optimal shrink factor (1.3)
int getNextGap(int gap) {
    gap = (gap * 10) / 13; // Equivalent to gap / 1.3
    
    // The gap cannot drop below 1
    if (gap < 1) {
        return 1;
    }
    return gap;
}

void combSort(int arr[], int n) {
    // Initialize gap size with array length
    int gap = n;
    
    // Set swapped to true to enter the primary loop execution
    bool swapped = true;

    // Keep running if the gap is greater than 1 or if swaps occurred in the last pass
    while (gap > 1 || swapped) {
        // Update the gap size for this pass
        gap = getNextGap(gap);

        // Reset swap flag before running the gapped comparison sweep
        swapped = false;

        // Compare all elements separated by the current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                
                // Flag that a swap happened (means array isn't fully sorted yet)
                swapped = true;
            }
        }
    }
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    combSort(arr, n);

    printf("\nSorted Array via Comb Sort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
