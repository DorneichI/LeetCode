/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* returnArray = malloc(numsSize * sizeof(int));
    int count;
    for (int i = 0; i < numsSize; i++) {
        count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i != j && nums[j] < nums[i]) count++;
        }
        returnArray[i] = count;
    }
    *returnSize = numsSize;
    return returnArray;
}
