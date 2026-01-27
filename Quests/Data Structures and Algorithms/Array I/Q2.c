

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* returnArray = malloc(numsSize * sizeof(int));
    for (int i = 0; i < n; i++) {
        returnArray[i * 2] = nums[i];
        returnArray[i * 2 + 1] = nums[i + n];
    }
    *returnSize = numsSize;
    return returnArray;
}
