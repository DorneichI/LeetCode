/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int* returnArray = malloc(numsSize * sizeof(int));
    int i;
    returnArray[0] = 0;
    for (i = 1; i < numsSize; i++) {
        returnArray[i] = returnArray[i - 1] + nums[i - 1];
    }
    int sum = 0;
    for (i = numsSize - 2; i >= 0; i--) {
        sum += nums[i + 1];
        returnArray[i] = abs(returnArray[i] - sum);
    }
    *returnSize = numsSize;
    return returnArray;
}