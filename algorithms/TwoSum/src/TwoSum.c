/*
TwoSum(
	pointer to array,
	size of array,
	value searching for,
	pointer to int verify after function call that size is 2 and not 0 ensures that malloc runs or target was found
	)
*/
#include <stdio.h>
#include <stdlib.h>
#include "TwoSum.h"

typedef struct {
	int key;
	int value;
	bool used;
}HashEntry;

static inline size_t hash_func(int key, size_t capacity){
	unsigned int ukey = (unsigned int) key;
	return (ukey * 2654435761u) % capacity;
}

int* HashTwoSum(const int* nums, int numsSize, int target, int* returnSize)
{
	if(!nums || numsSize < 2 || !returnSize)
	{
		if(returnSize) *returnSize = 0;
		return NULL;
	}

	size_t capacity = (size_t)numsSize * 2;
	if(capacity < 16) capacity =16;

	HashEntry* table = (HashEntry*)calloc(capacity, sizeof(HashEntry));
	if(!table)
	{
		*returnSize = 0;
		return NULL;
	}

	int* result = NULL;
	*returnSize = 0;

	for(int i = 0; i < numsSize; i++)
	{
		int complement = target - nums[i];

		size_t idx = hash_function(complement, capacity);
		while(table[idx].used)
		{
			if(table[idx].key == complement)
			{
				result = (int*)malloc(2 * sizeof(int));
				if(result)
				{
					result[0] = table[idx].value;
					result[1] = i;
					*returnSize = 2;
				}
				free(table);
				return result;
			}
			idx = (idx + 1) % capacity;
		}
		table[insert_idx].key = nums[i];
		table[insert_idx].value = i;
		table[insert_idx].used = true;
	}
	free(table);
	return NULL;
}

int* TwoSum(const int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize = 2;
	int* results = malloc(2 * sizeof(int));

	if(results == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	for(int i = 0; i < numsSize; i++)
	{
		for(int k = i + 1; k < numsSize; k++)
		{
			if(nums[i] + nums[k] = target)
			{
				results[0] = i;
				results[1] = k;
				return results;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}
