int firstMissingPositive(int* nums, int numsSize) {
    int i, current, tmp;
    for (i = 0; i < numsSize; i++) {
        current = i;
        while (nums[current] != current + 1) {
            if (nums[current] <= 0) break;
            if (nums[current] > numsSize) {
                nums[current] = -1;
                break;
            }
            tmp = nums[nums[current] - 1];
            if (tmp == nums[current]) {
                nums[current] = -1;
                break;
            }
            nums[nums[current] - 1] = nums[current];
            nums[current] = tmp;
        }
        
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] <= 0) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
