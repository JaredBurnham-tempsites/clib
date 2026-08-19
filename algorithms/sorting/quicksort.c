#include <stdio.h>
void printarr(int arr[], int size){
 for(int i = 0; i < size; i++){
  printf("%d | ", arr[i]);
 }
 printf("\n");
}
void quicksort(int array[], int low, int high);

int partition(int array[], int low, int high);

int main(){
 int myArray[] = {64,34,25,12,22,11,90,5};
 int n = sizeof(myArray) / sizeof(myArray[0]);

 quicksort(myArray, 0, n-1);
 printarr(myArray, 8);
 return 0;
}


void quicksort(int array[], int low, int high){
 if(low < high){
  int pivotIndex = partition(array, low, high);
  quicksort(array, low, pivotIndex - 1);
  quicksort(array, pivotIndex + 1, high);
 }
 printarr(array, 8);
}

int partition(int array[], int low, int high){
 int pivot = array[high];
 int i = low - 1;

 for(int j = low; j<high; j++){
  if(array[j] <= pivot){
   i++;
   int temp = array[i];
   array[i] = array[j];
   array[j] = temp;
  }
 }
 int temp = array[i+1];
 array[i+1] = array[high];
 array[high] = temp;
 return i + 1;
}
