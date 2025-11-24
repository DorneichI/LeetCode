void rotate(int* nums, int numsSize, int k) {
    int *cpy = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        cpy[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = cpy[i];
    }
    free(cpy);
}