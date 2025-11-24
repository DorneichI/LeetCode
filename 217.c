void merge(int *nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftNums[n1], rightNums[n2];

    for (int i = 0; i < n1; i++) {
        leftNums[i] = nums[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightNums[i] = nums[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftNums[i] < rightNums[j]) {
            nums[k++] = leftNums[i++];
        } else {
            nums[k++] = rightNums[j++];
        }
    }
    while (i < n1) {
        nums[k++] = leftNums[i++];
    }
    while (j < n2) {
        nums[k++] = rightNums[j++];
    }
}

void mergeSort(int *nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}

bool containsDuplicate(int* nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) return 1;
    }
    return 0;
}