

int longestValidParentheses(char* s) {
    int both = 0;
    int thing;
    for (thing = 0; s[thing] != '\0' && both == 0; thing++) {
        if (s[thing] == '(') {
            both++;
        }
    }
    for (thing = 0; s[thing] != '\0' && both == 1; thing ++) {
        if (s[thing] == ')') {
            both++;
        }
    }
    if (both < 2) return 0;

    int size = 4;
    int *memo = malloc(size * sizeof(int));
    int i = 0;
    int depth = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (i >= size) {
            size *= 2;
            memo = realloc(memo, size * sizeof(int));
        }
        if (s[i] == '(') {
            depth++;
            memo[i] = depth;
        } else {
            memo[i] = depth;
            depth--;
            
        }
    }

    int min = 100000;
    int max = -100000;
    for (int j = 0; j < i; j++) {
        if (memo[j] > max) {
            max = memo[j];
        }
        if (memo[j] < min) {
            min = memo[j];
        }
    }
    int longest = 0;
    for (int k = min; k <= max; k++) {
        int start = -1;
        int lengthK = 0;
        for (int j = 0; j < i; j++) {
            if (memo[j] == k && start < 0) {
                if (s[j] != ')') {
                    start = j;
                }
            } else if (memo[j] == k && start >= 0) {
                if (s[j] != '(') {
                    lengthK = j - start + 1;
                    if (lengthK > longest) {
                        longest = lengthK;
                    }
                }
            }
            if (memo[j] < k) {
                start = -1;
            }
        }
    }
    return longest;
}