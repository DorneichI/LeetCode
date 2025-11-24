bool isOneBitCharacter(int* bits, int bitsSize) {
    int possible[bitsSize];
    memset(possible, 0, sizeof(int) * bitsSize);
    possible[0] = 1;
    for (int i = 0; i < bitsSize - 1; i++) {
        if (possible[i]) {
            if (bits[i] == 0) {
                possible[i + 1] = 1;
            } else if (i + 2 < bitsSize) {
                possible[i + 2] = 1;
            }
        }
    }
    return possible[bitsSize-1];
}