int countValidSelections(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int result = 0;
    int left = 0;
    int found = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            if (left == sum - left) {
                result += 2;
                found = 1;
            } else if (left == sum - left + 1 || left + 1 == sum - left) {
                result += 1;
                found = 1;
            } else if (found != 0) {
                break;
            }
        } else {
            left += nums[i];
        }
    }
    return result;
}