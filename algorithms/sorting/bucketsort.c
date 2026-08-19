#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a bucket's elements via a linked list
struct Node {
    float data;
    struct Node* next;
};

// Function to sort individual buckets using Insertion Sort
struct Node* InsertionSort(struct Node* list) {
    if (!list || !list->next) {
        return list;
    }
    
    struct Node* sorted = NULL;
    struct Node* current = list;
    
    while (current != NULL) {
        struct Node* next = current->next;
        
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

// Main Bucket Sort Function
void BucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Put array elements into their respective buckets
    for (int i = 0; i < n; i++) {
        struct Node* current = (struct Node*)malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = NULL;
        
        int bucketIndex = (int)(arr[i] * n); // Map values to [0, n-1]
        
        // Insert into the head of the respective bucket list
        current->next = buckets[bucketIndex];
        buckets[bucketIndex] = current;
    }

    // 3. Sort individual buckets and gather elements back into arr[]
    int arrIndex = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = InsertionSort(buckets[i]);
        
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[arrIndex++] = temp->data;
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree); // Free memory allocated for nodes
        }
    }
    free(buckets); // Free bucket container
}

int main() {
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);

    BucketSort(arr, n);

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
