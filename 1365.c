/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *returnNums = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int count;
    for (int i = 0; i < numsSize; i++) {
        count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] < nums[i]) count ++;
        }
        returnNums[i] = count;
    }
    return returnNums;
}
