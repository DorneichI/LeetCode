/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double* returnArray = malloc(2 * sizeof(double));
    returnArray[0] = celsius + 273.15;
    returnArray[1] = celsius * 1.8 + 32;
    *returnSize = 2;
    return returnArray;
}