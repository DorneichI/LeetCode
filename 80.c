int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int k = 0;
    int l = 1;
    int two = 0;
    while (l < numsSize) {
        if (nums[k] == nums[l] && two) {
            l++;
        } else {
            if (nums[k] == nums[l]) {
                two = 1;
            } else {
                two = 0;
            }
            nums[k+1] = nums[l];
            k++;
            l++;
        }
    }
    return k + 1;
}