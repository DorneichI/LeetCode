int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int k = 0;
    int l = 1;
    while (l < numsSize) {
        if (nums[k] == nums[l]) {
            l++;
        } else {
            nums[k+1] = nums[l];
            k++;
            l++;
        }
    }
    return k + 1;
}