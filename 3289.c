/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int found = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        while (nums[i] != i) {
            int tmp;
            if (nums[nums[i]] == nums[i]) {
                found++;
                tmp = nums[numsSize - found];
                nums[numsSize - found] = nums[i];
                nums[i] = tmp;
                if (found == 2) break;
            }
            tmp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
        }
    }
    *returnSize = 2;
    return &nums[numsSize - 2];
}