

char * interpret(char * command){
    size_t size;
    for (size = 0; command[size] != '\0'; size++) {}
    char *string = malloc((size + 1) * sizeof(char));
    size_t index = 0;
    size = 0;
    while (command[size] != '\0') {
        if (command[size] == 'G') {
            string[index++] = 'G';
            size++;
        } else if (command[size + 1] == ')') {
            string[index++] = 'o';
            size += 2;
        } else {
            string[index++] = 'a';
            string[index++] = 'l';
            size += 4;
        }
    }
    string[index] = '\0';
    return string;
}