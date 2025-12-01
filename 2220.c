int minBitFlips(int start, int goal) {
    int bits = start ^ goal;
    printf("%i\n", bits);
    int sum = 0;
    while (bits != 0) {
        if (bits % 2 == 1) sum++;
        bits /= 2;
    }
    return sum;
}