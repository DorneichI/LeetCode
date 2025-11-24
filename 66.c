/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;
    while (i >= 0) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        i--;
    }
    digits = calloc(digitsSize + 1, sizeof(int));
    digits[0] = 1;
    *returnSize = digitsSize + 1;
    return digits;
}