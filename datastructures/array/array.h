#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{
	void *data
	size_t size;
	size_t capacity;
	size_t element_size;
}Array;

Array Array_create(size_t element_size);

#endif
