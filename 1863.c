int subsetXORSum(int* nums, int numsSize) {
    int total = 1 << numsSize;
    int sum = 0;
    for (int mask = 0; mask < total; mask++) {
        int xor = 0;
        for (int i = 0; i < numsSize; i++) {
            if (mask & (1 << i)) {
                xor = xor ^ nums[i];
            }
        }
        sum += xor;
    }
    return sum;
}