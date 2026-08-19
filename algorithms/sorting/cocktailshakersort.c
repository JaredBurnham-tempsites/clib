#include <stdio.h>
#include <stdbool.h>

void cocktailShakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Reset the flag entering the loop, it might be false
        swapped = false;

        // 1. Forward Pass (Left to Right) - Moves the largest element to the end
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        // If nothing moved, the array is fully sorted
        if (!swapped) {
            break;
        }

        // Otherwise, reset the flag for the next pass
        swapped = false;

        // Move the end point back by one, because the item at 'end' is now sorted
        end--;

        // 2. Backward Pass (Right to Left) - Moves the smallest element to the start
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        // Move the start point forward by one, because the item at 'start' is now sorted
        start++;
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    cocktailShakerSort(arr, n);

    printf("\nSorted Array via Cocktail Shaker:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
