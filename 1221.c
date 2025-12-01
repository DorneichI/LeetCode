int balancedStringSplit(char* s) {
    int num = 0;
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'L') num++;
        else num--;
        if (num == 0) sum++;
    }
    return sum;
}