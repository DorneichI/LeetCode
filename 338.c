/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int* array = malloc((n + 1) * sizeof(int));
    array[0] = 0;
    if (n >= 1) array[1] = 1;
    if (n >= 2) array[2] = 1;
    int current = 2;
    int next = 4;
    for (int i = 3; i <= n; i++) {
        if (i == next) {
            current = next;
            next *= 2;
            array[i] = 1;
        } else {
            array[i] = array[i - current] + 1;
        }
        
    }
    *returnSize = n + 1;
    return array;
}