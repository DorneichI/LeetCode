/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
    int *returnArray = malloc(friendsSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < orderSize; i++) {
        for (int j = 0; j < friendsSize; j++) {
            if (order[i] == friends[j]) {
                returnArray[index++] = order[i];
                break;
            }
        }
    }
    *returnSize = friendsSize;
    return returnArray;
}