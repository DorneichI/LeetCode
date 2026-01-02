int repeatedNTimes(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] == nums[j]) {
                return nums[i];
            }
        }
    }
    return INT_MAX;
}
