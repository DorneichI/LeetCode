bool isPalindrome(char* s) {
    int size = 8;
    int index = 0;
    char* n = malloc(size * sizeof(char));

    while (*s) {
        if (isalnum(*s)) {
            while (index>= size) {
                size *= 2;
                n = realloc(n, size * sizeof(char));
            }
            n[index++] = tolower(*s);
        }
        s++;
    }

    for (int i = 0; i < index / 2; i++) {
        if (n[i] != n[index - 1 - i]) return 0;
    }
    return 1;
}