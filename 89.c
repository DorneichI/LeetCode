/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    result[0] = 0;
    result[1] = 1;
    int size = 2;
    int mask;
    for (int i = 2; i <= n; i++) {
        mask = size;
        size *= 2;
        result = realloc(result, size * sizeof(int));
        for (int j = 0; j < size / 2; j++) {
            result[size - j - 1] = result[j] | mask;
        }
    }
    *returnSize = size;
    return result;
}