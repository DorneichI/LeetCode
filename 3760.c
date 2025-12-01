int contains(char* string, char c) {
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] == c) return 0;
    }
    return 1;
}

int maxDistinct(char* s) {
    size_t size;
    for (size = 0; s[size] != '\0'; size++);
    char* distinct = malloc((size + 1) * sizeof(char));
    distinct[0] = '\0';
    size_t index = 0;
    int sum = 0;
    for (size_t i = 0; s[i] != '\0'; i++) {
        if (contains(distinct, s[i]) != 0) {
            distinct[index++] = s[i];
            distinct[index] = '\0';
            sum++;
        }
    }
    return sum;
}