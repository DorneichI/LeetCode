int getChar(char c) {
    if (c == '0') {
        return 10;
    } else if (c == '1') {
        return 1;
    } else if (c == '2') {
        return 2;
    } else if (c == '3') {
        return 3;
    } else if (c == '4') {
        return 4;
    } else if (c == '5') {
        return 5;
    } else if (c == '6') {
        return 6;
    } else if (c == '7') {
        return 7;
    } else if (c == '8') {
        return 8;
    } else if (c == '9') {
        return 9;
    } else {
        return 0;
    }
}

int myAtoi(char* s) {
    while (*s == ' ') {
        s++;
    }
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    while (*s == '0') {
        s++;
    }
    int nextChar = getChar(*s);
    s++;
    int size = 4;
    int index = 0;
    int* array = malloc(size * sizeof(int)); 
    while (nextChar) {
        while (index >= size) {
            size *= 2;
            array = realloc(array, size * sizeof(int));
        }
        array[index] = (nextChar == 10) ? 0 : nextChar;
        index++;
        nextChar = getChar(*s);
        s++;
    }
    if (index > 15 && sign > 0) return INT_MAX;
    if (index > 15 && sign < 0) return INT_MIN;
    long result = 0;
    for (int i = 0; i < index; i++) {
        result *= 10;
        result += array[i];
    }
    if (result * sign > INT_MAX) {
        return INT_MAX;
    } else if (result * sign < INT_MIN) {
        return INT_MIN;
    }
    return result * sign;
}