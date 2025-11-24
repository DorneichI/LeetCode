bool isSubsequence(char* s, char* t) {
    int i, j, k;
    if (s[0] == '\0') return 1;
    for (i = 0; t[i] != '\0'; i++) {
        k = 0;
        if (t[i] == s[k++]) {
            for (j = i + 1; t[j] != '\0'; j++) {
                if (t[j] == s[k]) k++;
            }
            if (s[k] == '\0') return 1;
        }
    }
    return 0;
}