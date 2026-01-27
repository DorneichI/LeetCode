/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* returnArray = malloc(2 * numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        returnArray[i] = nums[i];
        returnArray[i + numsSize] = nums[i];
    }
    *returnSize = 2 * numsSize;
    return returnArray;
}
//     *returnSize = numsSize * 2;
//     int *returnNums = malloc(*returnSize * sizeof(int));
//     int i;
//     for (i = 0; i < numsSize; i++) {
//         returnNums[i] = nums[i];
//     }
//     for (i = 0; i < numsSize; i++) {
//         returnNums[i + numsSize] = nums[i];
//     }
//     return returnNums;
// }
