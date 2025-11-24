bool canJump(int* nums, int numsSize) {
    int jump = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] >= jump) {
            jump = 1;
        } else {
            jump++;
        }
    }
    return jump <= 1;
}