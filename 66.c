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

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* plusOne(int* digits, int digitsSize, int* returnSize) {
//     *returnSize = digitsSize;
//     while (digits[--digitsSize] == 9 && digitsSize > 0) {
//         digits[digitsSize] = 0;
//     }
//     digits[digitsSize]++;
//     int* returnDigits;
//     if (digits[digitsSize] > 9) {
//         (*returnSize)++;
//         returnDigits = malloc(*returnSize * sizeof(int));
//         memset(returnDigits, 0, *returnSize * sizeof(int));
//         returnDigits[0] = 1;
//         return returnDigits;
//     }
//     return digits;
// }
