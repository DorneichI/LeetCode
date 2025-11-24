int minNumberOperations(int* target, int targetSize) {
    int incrementing = 1;
    int lastLocal = 0;
    int total = 0;
    if (targetSize == 1) return target[0];
    for (int i = 1; i < targetSize; i++) {
        if (target[i] < target[i - 1] && incrementing) {
            incrementing = 0;
            total += target[i - 1] - lastLocal;
            lastLocal = target[i - 1];
        } else if (target[i] > target[i - 1] && !incrementing) {
            incrementing = 1;
            lastLocal = target[i - 1];
        }
    }
    if (target[targetSize - 1] > lastLocal) {
        total += target[targetSize - 1] - lastLocal;
    }
    return total;
}