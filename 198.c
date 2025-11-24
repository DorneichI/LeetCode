int rob(int* nums, int numsSize) {
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        if (a + nums[i] > b + nums[i]) {
            b = c;
            c = a + nums[i];
        } else {
            a = c;
            c = b + nums[i];
        }
    }
    if (a > b && a > c) return a;
    else if (b > a && b > c) return b;
    else return c;
}