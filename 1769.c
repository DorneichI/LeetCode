/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int* array = malloc(2000 * sizeof(int));
    int i;
    int sum;
    for (i = 0; boxes[i] != '\0'; i++) {
        sum = 0;
        for (int j = 0; boxes[j] != '\0'; j++) {
            if (boxes[j] == '1') sum += abs(i - j);
        }
        array[i] = sum;
        sum = 0;
    }
    *returnSize = i;
    return array;
}
