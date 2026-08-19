#include <stdio.h>
#include <stdlib.h>

#define INSERTION_THRESHOLD 16

// Swap helper function
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// --- PHASE 3: INSERTION SORT ---
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// --- PHASE 2: HEAPSORT SUPPORT FUNCTIONS ---
void heapify(int arr[], int n, int i, int base) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[base + left] > arr[base + largest])
        largest = left;

    if (right < n && arr[base + right] > arr[base + largest])
        largest = right;

    if (largest != i) {
        swap(&arr[base + i], &arr[base + largest]);
        heapify(arr, n, largest, base);
    }
}

void heapSort(int arr[], int left, int right) {
    int n = right - left + 1;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, left);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[left], &arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

// --- PHASE 1: QUICKSORT PARTITIONING ---
int partition(int arr[], int low, int high) {
    // Median-of-three pivot selection to prevent bad splits
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(&arr[mid], &arr[low]);
    if (arr[high] < arr[low]) swap(&arr[high], &arr[low]);
    if (arr[mid] < arr[high]) swap(&arr[mid], &arr[high]);
    
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Master Introsort Recursive Core
void introsortUtil(int arr[], int left, int right, int depthLimit) {
    int size = right - left + 1;

    // If data size is too small, skip partitioning and handle in final pass
    if (size < INSERTION_THRESHOLD) {
        return;
    }

    // If we hit the recursion ceiling, fallback to Heapsort to ensure O(n log n)
    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }

    // Otherwise, perform regular Quicksort partitioning
    int pivotIndex = partition(arr, left, right);
    introsortUtil(arr, left, pivotIndex - 1, depthLimit - 1);
    introsortUtil(arr, pivotIndex + 1, right, depthLimit - 1);
}

// Wrapper Function for Introsort
void introSort(int arr[], int n) {
    if (n < 2) return;

    // Compute floor(log2(n)) * 2 to set the recursion limit
    int depthLimit = 0;
    int temp = n;
    while (temp >>= 1) depthLimit++;
    depthLimit *= 2;

    // Run the primary introspective partitioning phase
    introsortUtil(arr, 0, n - 1, depthLimit);

    // Run final Insertion Sort to clean up left-over small array groupings
    insertionSort(arr, 0, n - 1);
}

int main() {
    int arr[] = {34, -10, 50, 42, 8, -5, 12, 100, 2, 75, 60, 23, 1, 9, 18, 4, 11, 14, 0, -20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    introSort(arr, n);

    printf("\nSorted Array via Introsort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
