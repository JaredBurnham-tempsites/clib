#include <stdio.h>

void gnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        // If we are at the start, or elements are in the right order, move forward
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } 
        // If elements are out of order, swap them and step backward
        else {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

int main() {
    int arr[] = {34, -10, 50, 42, 8, -5, 1};
    int n = sizeof(arr) / sizeof(arr);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    gnomeSort(arr, n);

    printf("\nSorted Array via Gnome Sort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
