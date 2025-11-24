bool kLengthApart(int* nums, int numsSize, int k) {
    int distanceToOne = 0;
    int found = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] && !found) {
            found = 1;
            distanceToOne = 0;
        } else if (nums[i] && distanceToOne < k) {
            return 0;
        } else if (nums[i]) {
            distanceToOne = 0;
        } else {
            distanceToOne++;
        }
    }
    return 1;
}