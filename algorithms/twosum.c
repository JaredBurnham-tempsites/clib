int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* results = malloc(2 * sizeof(int));
    if(results == NULL){
        *returnSize = 0;
        return NULL;
    }

    for(int i = 0; i < numsSize; i++){
        for(int k = i + 1; k < numsSize; k++){
            if(nums[i] + nums[k] == target){
                results[0] = i;
                results[1] = k;
                return results;
            }
        }
    } 
    return NULL;
}
