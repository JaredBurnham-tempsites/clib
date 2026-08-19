#include <stdio.h>

int main(){
 int arr[] = {1,2,4,1,4,3,5,3,8};
 int length = sizeof(arr) / sizeof(arr[0]);
 int maxvalue = arr[0];
 //find max value in array
 for(int i = 1; i<length; i++){
  if(arr[i] > maxvalue){
   maxvalue = arr[i];
  }
 }
 int countingarray[maxvalue + 1];
 for(int l = 0; l<maxvalue;l++){
  countingarray[l] = 0;
 }
 for(int j = 0; j<=length; j ++){
  countingarray[arr[j]] ++;
 }
 int index = 0;
 for(int i = 0; i < maxvalue; i++){
  while(countingarray[i] > 0){
   arr[index++] = i;
   countingarray[i]--;
  }
 }

 for(int k = 0; k < length; k++){
  printf("%d | ", arr[k]);
 }
 printf("\n");
 return 0;
}
