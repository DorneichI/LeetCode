/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    int num = 0;
    _Bool *returnArray = malloc(numsSize * sizeof(_Bool));
    for (int i = 0; i < numsSize; i++) {
        num *= 2;
        num += nums[i];
        num = num % 5;
        returnArray[i] = num == 0;
    }
    *returnSize = numsSize;
    return returnArray;
}