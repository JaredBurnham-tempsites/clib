#include <stdio.h>

void heapify(int *arr,int heap_size, int index);

int main(){
	int arr[5] = {4,10,3,5,1};

	for(int j = 0; j<5; j++){
		printf("%d  ", arr[j]);
	}
	printf("\n");
	heapify(arr, 5, 0);
	for (int i = 0; i<5; i++){
		printf("%d\n", arr[i]);
	}

}

void heapify(int arr[], int heap_size, int index){
	for(int i = 0; i<heap_size; i++){
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		int highest;

		if(i + l < 5){
			if(i + r < 5){
				if(arr[i] < arr[i+r]){
					highest = arr[i + r];
					arr[i + r] = arr[i];
					arr[i] = highest;
				}
			}
			if(arr[i] < arr[i +l]){
				highest = arr[i +l];
				arr[i + l] = arr[i];
				arr[i] = highest;
			}
		}
	}

}
