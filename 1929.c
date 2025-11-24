/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize * 2;
    int *returnNums = malloc(*returnSize * sizeof(int));
    int i;
    for (i = 0; i < numsSize; i++) {
        returnNums[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        returnNums[i + numsSize] = nums[i];
    }
    return returnNums;
}