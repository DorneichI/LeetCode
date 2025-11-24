

char * defangIPaddr(char * address){
    char* defanged = malloc(22 * sizeof(char));
    int i;
    int j = 0;
    for (int i = 0; address[i] != '\0'; i++) {
        if (address[i] == '.') {
            defanged[j++] = '[';
            defanged[j++] = '.';
            defanged[j++] = ']';
        } else {
            defanged[j++] = address[i];
        }
    }
    defanged[j] = '\0';
    return defanged;
}