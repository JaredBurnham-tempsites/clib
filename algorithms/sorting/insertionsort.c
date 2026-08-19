#include <stdio.h>
//o(n^2)
// got through the array forward
// at each element then go through the array backwards
// if i value is greater than j value and we are not at front of arr
// continue looking for and updating insertion index
// once found insert value at insertion index
// go forward on i value
int main(){
 int arr[] = {64, 34, 25,12,22,11,90,5};
 int length = 8;
 for( int i = 1; i < length; i++){
  int insertIndex = i;
  int currentValue = arr[i];
  int j = i - 1;

  while(j >= 0 && arr[j] > currentValue){
   for(int k = 0; k<length; k++){printf("%d | ", arr[k]);}
   printf("\n");
   arr[j + 1] = arr[j];
   insertIndex = j;
   j--;
  }
  arr[insertIndex] = currentValue;
 }
 for(int i = 0; i < length; i++){
  printf("%d\n", arr[i]);
 }
 return 0;
}
