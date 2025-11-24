int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int largest = 0;
    int current;
    for (int m = 0; m < accountsSize; m++) {
        current = 0;
        for (int n = 0; n < *accountsColSize; n++) {
            current += accounts[m][n];
        }
        if (current > largest) largest = current;
    }
    return largest;
}