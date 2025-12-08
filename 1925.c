int countTriples(int n) {
    int* squares = malloc(n * sizeof(int));
    int i, j, k;
    for (i = 1; i <= n; i++) {
        squares[i - 1] = pow(i, 2);
    }
    int result = 0;
    int sum;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            sum = squares[i] + squares[j];
            for (k = i + 1; k < n; k++) {
                if (sum == squares[k]) {
                    if (j == i) result++;
                    else result += 2;
                    break;
                }
            }
        }
    }
    free(squares);
    return result;
}