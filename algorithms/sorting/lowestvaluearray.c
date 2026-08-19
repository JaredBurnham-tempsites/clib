#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
 srand(time(NULL));
 int arr[10];
 int length = sizeof(arr) / sizeof(arr[0]);
 int i;
 int rando;
 for(i = 0; i < length; i++){
  rando = rand();
  arr[i] = rando;
 }

//actuall algorithm ########## O of n | O(n)
 int lowestnumber = arr[0];
 for(i = 0; i < length; i++){
  if(lowestnumber > arr[i]){lowestnumber = arr[i];}
 }
 printf("%d\n\n", lowestnumber);
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 for(i = 0; i<length;i++){printf("%d\n",arr[i]);}
 return 0;
}
