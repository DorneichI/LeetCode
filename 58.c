int lengthOfLastWord(char* s) {
    int length = 0;
    int new_word = 0;
    while (*s != '\0') {
        if (*s == ' ') {
            new_word = 0;
        } else if (!new_word) {
            length = 1;
            new_word = 1;
        } else {
            length++;
        }
        s++;
    }
    return length;
}