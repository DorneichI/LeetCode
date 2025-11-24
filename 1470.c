

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* array = malloc(numsSize * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[2 * i] = nums[i];
        array[2 * i + 1] = nums[n + i];
    }
    *returnSize = numsSize;
    return array;
}