#include <stdio.h>
//bubble sort is o(n^2)
void arrdisplay(int arr[], int length);

int main(){
 int arr[8] = {64, 34, 25, 12, 22, 11, 90, 5};
 int length = 8;
 int i;
 int j;
 int temp;
 int swapped;
 for(i = 0; i < length -1; i++){
//added efficiency
  swapped = 1;
  for(j = 0; j < length - i - 1; j++){
   if(arr[j] > arr[j+1]){
    temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
    arrdisplay(arr, length);
//added efficiency
    swapped = 0;
   }
  }
//saves time if no swaps are performed in a loop
  if(swapped == 0){break;}
//#############
 }

 for(i = 0; i< length; i++){
  printf("%d\n", arr[i]);
 }
 return 0;
}

void arrdisplay(int arr[], int length){
 int i;
 for(i = 0; i< length; i++){
  printf(" %d | ", arr[i]);
 }
 printf("\n");
}
