#include <stdio.h>
//always o(n^2)
int main(){
 int arr[6] = {9,23,983,12,43,435};
 int i;
 int j;
 int min;
 int temp;
for(i = 0; i < 5; i++){
  min = i;
  for(j = i + 1; j < 6; j++){
   if(arr[min] > arr[j]){
    min = j;
   }
  }
 if(min != i){
  temp = arr[min];
  arr[min] = arr[i];
  arr[i] = temp;
 }
 }
 for(i = 0; i < 6; i ++){
  printf("%d\n", arr[i]);
 }
}
