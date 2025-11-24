int mySqrt(int x) {
    if (x <= 1) return x;
    for (int i = 0; i <= x; i++) {
        if (i == 46341) return 46340;
        if (i * i > x) {
            return i - 1;
        }
    }
    return -1;
}