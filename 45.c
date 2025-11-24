int jump(int* nums, int numsSize) {
    int jumps[numsSize];
    jumps[0] = 0;
    int furthest = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = furthest; j < i + nums[i] + 1 && j < numsSize; j++) {
            jumps[j] = jumps[i] + 1;
        }
        if (i + nums[i] + 1 >= numsSize) {
            break;
        } else if (i + nums[i] + 1 > furthest) {
            furthest = i + nums[i] + 1;
        }
    }
    return jumps[numsSize - 1];
}