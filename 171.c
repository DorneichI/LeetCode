int titleToNumber(char* columnTitle) {
    int length;
    for (length = 0; columnTitle[length] != '\0'; length++);
    int* characters = malloc(7 * sizeof(int));
    int i;
    for (i = 0; i < length; i++) {
        characters[i] = columnTitle[i] - 'A' + 1;
    }
    int total = 0;
    for (i = 0; i < length; i++) {
        total += characters[length - i - 1] * pow(26, i);
    }
    free(characters);
    return total;
}
