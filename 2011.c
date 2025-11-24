int finalValueAfterOperations(char** operations, int operationsSize) {
    int value = 0;
    char *add1 = "X++";
    char *add2 = "++X";
    for (int i = 0; i < operationsSize; i++) {
        if (!strcmp(operations[i], add1) || !strcmp(operations[i], add2)) {
            value++;
        } else {
            value--;
        }
    }
    return value;
}