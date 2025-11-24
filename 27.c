int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return 0;
    int k = 0;
    int l = 0;
    while (l < numsSize) {
        if (nums[l] == val) {
            l++;
        } else {
            nums[k] = nums[l];
            k++;
            l++;
        }
    }

    return k;
}