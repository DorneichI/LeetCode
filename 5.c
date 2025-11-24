int isPalindrome(char* s, int l) {
    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l- i - 1]) {
            return 0;
        }
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int l;
    for (l = 0; s[l] != '\0'; l++) {}
    int longest = 1;
    for (int i = l; i >= 2; i--) {
        for (int j = 0; j < l - i + 1; j++) {
            if (isPalindrome(&s[j], i)) {
                s[j+i] = '\0';
                return &s[j];
            }
        }
    }
    s[1] = '\0';
    return s;
}