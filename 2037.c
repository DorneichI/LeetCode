void merge(int* array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArray[n1], rightArray[n2];
    for (i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] < rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }
    while (i < n1) {
        array[k++] = leftArray[i++];
    }
    while (j < n2) {
        array[k++] = rightArray[j++];
    }
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    mergeSort(seats, 0, seatsSize - 1);
    mergeSort(students, 0, studentsSize - 1);

    int sum = 0;
    for (int i = 0; i < seatsSize; i++) {
        sum += abs(seats[i] - students[i]);
    }
    return sum;
}