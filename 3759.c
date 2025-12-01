void merge(int* nums, int left, int mid, int right) {
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int* leftArray = malloc(leftSize * sizeof(int));
    int* rightArray = malloc(rightSize * sizeof(int));
    
    for (i = 0; i < leftSize; i++) leftArray[i] = nums[left + i];
    for (j = 0; j < rightSize; j++) rightArray[j] = nums[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] < rightArray[j]) {
            nums[k++] = leftArray[i++];
        } else {
            nums[k++] = rightArray[j++];
        }
    }
    while (i < leftSize) {
        nums[k++] = leftArray[i++];
    }
    while (j < rightSize) {
        nums[k++] = rightArray[j++];
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int* nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

int countElements(int* nums, int numsSize, int k) {
    if (k == 0) return numsSize;
    mergeSort(nums, 0, numsSize - 1);
    for (int i = numsSize - k - 1; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) return i + 1;
    }
    return 0;
}