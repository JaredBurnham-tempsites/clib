#include "array.h"

Array Array_create(size_t element_size){
	Array arr;

	arr.size = 0;
	arr.capacity = 1;
	arr.element_size = element_size;

	arr.data = malloc(arr.capacity * element_size);

	return arr;
}

void push(void *arr, const void *element){
	if(arr->size == arr->capacity){
		arr->capacity *= 2;
		void *temp = realloc(arr->data, arr->capacity * element_size);
		if(temp == NULL) {return;}
		arr->data = temp;
	}
	arr->size ++;
	arr->data[arr->size] = element;
}
