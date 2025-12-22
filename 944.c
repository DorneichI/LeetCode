int minDeletionSize(char** strs, int strsSize) {
    int i, j;
    int strSize;
    for (strSize = 0; strs[0][strSize] != '\0'; strSize++);
    int* toDelete = malloc(strSize * sizeof(int));
    memset(toDelete, 0, strSize * sizeof(int));
    for (i = 1; i < strsSize; i++) {
        for (j = 0; strs[i][j] != '\0'; j++) {
            if (toDelete[j] > 0) continue;
            if (strs[i][j] < strs[i - 1][j]) toDelete[j] = 1;
        }
    }
    int result = 0;
    for (i = 0; i < strSize; i++) {
        if (toDelete[i] > 0) result++;
    }
    free(toDelete);
    return result;
}
