int findPermutationDifference(char* s, char* t) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; t[j] != '\0'; j++) {
            if (s[i] == t[j]) {
                sum += abs(i - j);
                break;
            }
        }
    }
    return sum;
}