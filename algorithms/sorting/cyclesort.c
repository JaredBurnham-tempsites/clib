#include <stdio.h>

void cycleSort(int arr[], int n) {
    // Loop through the array to find cycles to rotate
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];

        // 1. Find the position where the item should go
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // If the item is already in the correct position, skip this cycle
        if (pos == cycle_start) {
            continue;
        }

        // 2. If there are duplicate elements, move past them
        while (item == arr[pos]) {
            pos++;
        }

        // 3. Put the item into its correct position
        if (pos != cycle_start) {
            int temp = arr[pos];
            arr[pos] = item;
            item = temp;
        }

        // 4. Rotate the rest of the cycle until we return to cycle_start
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find the position for the current item
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // Move past duplicate elements
            while (item == arr[pos]) {
                pos++;
            }

            // Put the item into its correct position
            if (item != arr[pos]) {
                int temp = arr[pos];
                arr[pos] = item;
                item = temp;
            }
        }
    }
}

int main() {
    int arr[] = {10, 4, 4, 1, 8, 2, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    cycleSort(arr, n);

    printf("\nSorted Array via Cycle Sort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
