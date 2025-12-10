int countPermutations(int* complexity, int complexitySize) {
    int i;
    long result = 1;
    for (i = 1; i < complexitySize; i++) {
        if (complexity[i] <= complexity[0]) return 0;
        result = (result * i) % 1000000007;
    }
    return (int)result;
}