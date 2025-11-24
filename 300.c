int lengthOfLIS(int* nums, int numsSize) {
    int* length = malloc(numsSize * sizeof(int));
    memset(length, 0, numsSize * sizeof(int));
    int maxNum = nums[numsSize - 1];
    int max = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] >= maxNum) {
            maxNum = nums[i];
            length[i] = 1;
        } else {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] > nums[i] && length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    if (length[i] > max) max = length[i];
                }
            }
        }
    }
    return max;
}