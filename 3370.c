int smallestNumber(int n) {
    int i;
    for (i = 2; i - 1 < n; i *= 2) {}
    return i - 1;
}