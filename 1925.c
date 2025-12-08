int countTriples(int n) {
    int hashTableSize = n * n;
    int* hashTable = malloc(hashTableSize * sizeof(int));
    memset(hashTable, 0, hashTableSize * sizeof(int));
    int* squares = malloc(n * sizeof(int));
    int i, j;
    for (i = 1; i <= n; i++) {
        squares[i - 1] = i * i;
        hashTable[squares[i - 1] - 1] = 1;
    }
    int sum;
    int result = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
           sum = squares[i] + squares[j];
           if (sum <= hashTableSize && hashTable[sum - 1] == 1) {
            if (i == j) result++;
            else result += 2;
           }
        }
    }
    return result;
}