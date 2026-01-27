void merge(int* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = malloc(n1 * sizeof(int));
    int* rightArr = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] < rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums, 0, numsSize - 1);
    int *output = malloc(2 * sizeof(int));
    output[1] = -1;
    int onIt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + onIt + 1) {
            if (onIt >= 0 && nums[i] <= i + 1) {
                output[0] = nums[i];
                onIt -= 1;
            } else if (onIt < 0) {
                output[1] = i;
                onIt += 1;
            } else {
                output[1] = i + 1;
                onIt += 1;
            }
        }
    }
    if (output[1] == -1) output[1] = numsSize;
    *returnSize = 2;
    return output;
}