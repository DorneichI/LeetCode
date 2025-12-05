int countPartitions(int* nums, int numsSize) {
    int sum = 0;
    int i;
    for (i = 0; i < numsSize; i++) sum += nums[i];
    int count = 0;
    int sum2 = 0;
    for (i = 0; i < numsSize - 1; i++) {
        sum2 += nums[i];
        if ((sum - 2 * sum2) % 2 == 0) count++;
    }
    return count;
}