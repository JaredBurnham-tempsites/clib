#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_MERGE 32

// Struct to keep track of runs on the merge stack
typedef struct {
    int base;
    int len;
} Run;

// 1. Calculate a dynamic minrun size to ensure balanced merge trees
int countMinRun(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

// 2. Binary Insertion Sort: Uses binary search to insert elements into a pre-sorted run
void binaryInsertionSort(int arr[], int lo, int hi, int start) {
    if (start == lo) start++;
    
    for (; start <= hi; start++) {
        int pivot = arr[start];
        int left = lo;
        int right = start;
        
        // Binary search to find the correct insertion slot
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pivot < arr[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Shift elements over to make room for the pivot
        int n = start - left;
        switch (n) {
            case 2:  arr[left + 2] = arr[left + 1];
            case 1:  arr[left + 1] = arr[left];
                     break;
            default: for (int m = start; m > left; m--) arr[m] = arr[m - 1];
        }
        arr[left] = pivot;
    }
}

// Reverses a descending sub-array segment in place
void reverseRange(int arr[], int lo, int hi) {
    hi--;
    while (lo < hi) {
        int t = arr[lo];
        arr[lo++] = arr[hi];
        arr[hi--] = t;
    }
}

// 3. Natural Run Finder: Scans and identifies pre-sorted data chunks
int countRunAndMakeAscending(int arr[], int lo, int hi) {
    if (lo == hi) return 1;
    int runHi = lo + 1;
    if (runHi == hi) return 1;

    // Descending run check
    if (arr[runHi] < arr[lo]) { 
        while (runHi < hi && arr[runHi] < arr[runHi - 1]) {
            runHi++;
        }
        reverseRange(arr, lo, runHi);
    } else { // Ascending run check
        while (runHi < hi && arr[runHi] >= arr[runHi - 1]) {
            runHi++;
        }
    }
    return runHi - lo;
}

// Standard low-overhead Merge implementation for adjacent runs
void mergeLo(int arr[], int base1, int len1, int base2, int len2) {
    int* tmp = (int*)malloc(len1 * sizeof(int));
    for (int i = 0; i < len1; i++) tmp[i] = arr[base1 + i];

    int cursor1 = 0;
    int cursor2 = base2;
    int dest = base1;

    arr[dest++] = arr[cursor2++];
    len2--;
    if (len2 == 0) {
        for (int i = 0; i < len1; i++) arr[dest + i] = tmp[cursor1 + i];
        free(tmp);
        return;
    }

    while (true) {
        if (arr[cursor2] < tmp[cursor1]) {
            arr[dest++] = arr[cursor2++];
            if (--len2 == 0) break;
        } else {
            arr[dest++] = tmp[cursor1++];
            if (--len1 == 1) break;
        }
    }

    if (len1 == 1) {
        while (len2 > 0) {
            arr[dest++] = arr[cursor2++];
            len2--;
        }
        arr[dest] = tmp[cursor1];
    } else {
        while (len1 > 0) {
            arr[dest++] = tmp[cursor1++];
            len1--;
        }
    }
    free(tmp);
}

// 4. Stack Manager: Ensures A > B + C and B > C invariants are met to prevent stack unbalance
void mergeCollapse(int arr[], Run stack[], int* stackSize) {
    while (*stackSize > 1) {
        int n = *stackSize - 2;
        
        // Invariant A > B + C check
        if (n > 0 && stack[n - 1].len <= stack[n].len + stack[n + 1].len) {
            if (stack[n - 1].len < stack[n + 1].len) n--;
            
            // Merge run at index n with run at index n+1
            mergeLo(arr, stack[n].base, stack[n].len, stack[n + 1].base, stack[n + 1].len);
            stack[n].len += stack[n + 1].len;
            stack[n + 1] = stack[n + 2]; 
            (*stackSize)--;
        } 
        // Invariant B > C check
        else if (stack[n].len <= stack[n + 1].len) {
            mergeLo(arr, stack[n].base, stack[n].len, stack[n + 1].base, stack[n + 1].len);
            stack[n].len += stack[n + 1].len;
            (*stackSize)--;
        } else {
            break; // Invariants are satisfied
        }
    }
}

// Forces remaining items on stack to merge at the end
void mergeForceCollapse(int arr[], Run stack[], int* stackSize) {
    while (*stackSize > 1) {
        int n = *stackSize - 2;
        if (n > 0 && stack[n - 1].len < stack[n + 1].len) n--;
        
        mergeLo(arr, stack[n].base, stack[n].len, stack[n + 1].base, stack[n + 1].len);
        stack[n].len += stack[n + 1].len;
        stack[n + 1] = stack[*stackSize - 1];
        (*stackSize)--;
    }
}

// Master Timsort Algorithm Wrapper
void optimizedTimSort(int arr[], int n) {
    if (n < 2) return;

    int minRun = countMinRun(n);
    Run stack[85]; // A stack size of 85 safely handles arrays up to 2^64 size
    int stackSize = 0;

    int lo = 0;
    while (lo < n) {
        // Step A: Find next natural run length
        int runLen = countRunAndMakeAscending(arr, lo, n);

        // Step B: If natural run is too small, use binary insertion sort to expand it
        if (runLen < minRun) {
            int force = (n - lo <= minRun) ? (n - lo) : minRun;
            binaryInsertionSort(arr, lo, lo + force - 1, lo + runLen);
            runLen = force;
        }

        // Step C: Push run metrics onto our control stack
        stack[stackSize].base = lo;
        stack[stackSize].len = runLen;
        stackSize++;

        // Step D: Evaluate stability invariants on the stack
        mergeCollapse(arr, stack, &stackSize);

        lo += runLen;
    }

    // Clear remaining runs on stack to yield the final completely sorted array
    mergeForceCollapse(arr, stack, &stackSize);
}

int main() {
    int arr[] = {25, -4, 12, 4, 98, 33, 11, -12, 85, 42, 6, 0, 77, 24, 18, 9, 31, 5, 8, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Data Matrix:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    optimizedTimSort(arr, n);

    printf("\nOptimized Timsort Result:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
