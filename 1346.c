bool checkIfExist(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        int target = arr[i] * 2;
        for (int j = 0; j < arrSize; j++) {
            if (arr[j] == target && j != i) return 1;
        }
    }
    return 0;
}