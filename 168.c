char* convertToTitle(int columnNumber) {
    int size = 4;
    int index = 0;
    char* result = malloc(size * sizeof(char));
    char nextChar;
    while (columnNumber > 0) {
        nextChar = columnNumber % 26;
        columnNumber = columnNumber / 26;
        if (size == index) {
            size *= 2;
            result = realloc(result, size * sizeof(char));
        }
        if (nextChar == 0) {
            columnNumber--;
            result[index++] = nextChar + 64 + 26;
        } else {
            result[index++] = nextChar + 64;
        }
    }
    char* actual = malloc(index + 1 * sizeof(char));
    for (int i = 0; i < index; i++) {
        actual[i] = result[index - i - 1];
    }
    free(result);
    actual[index] = '\0';
    return actual;
}