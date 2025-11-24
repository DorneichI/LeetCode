bool isAnagram(char* s, char* t) {
    int lengthS;
    for (lengthS = 0; s[lengthS] != '\0'; lengthS++) {}
    int lengthT;
    for (lengthT = 0; t[lengthT] != '\0'; lengthT++) {}
    if (lengthT != lengthS) return 0;
    char tmp;
    for (int i = 0; i < lengthS; i++) {
        int found = 0;
        for (int j = i; j < lengthT; j++) {
            if (t[j] == s[i]) {
                found = 1;
                t[j] = t[i];
                break;
            }
        }
        if (found == 0) {
            return 0;
        }
        found = 0;
    }
    return 1;
}