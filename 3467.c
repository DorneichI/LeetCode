/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    int* returnArray = malloc(numsSize * sizeof(int));
    int front = 0;
    int back = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            returnArray[front++] = 0;
        } else {
            returnArray[back--] = 1;
        }
    }
    *returnSize = numsSize;
    return returnArray;
}