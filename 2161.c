/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* array = malloc(numsSize * sizeof(int));
    int index = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            array[index++] = nums[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == pivot) {
            array[index++] = nums[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > pivot) {
            array[index++] = nums[i];
        }
    }
    *returnSize = numsSize;
    return array;
}