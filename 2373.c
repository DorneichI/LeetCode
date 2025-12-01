/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int** returnGrid = malloc((gridSize - 2) * sizeof(int*));
    *returnSize = gridSize - 2;
    int i;
    *returnColumnSizes = malloc((gridSize - 2) * sizeof(int));
    for (i = 0; i < gridSize - 2; i++) {
        returnGrid[i] = malloc((gridColSize[i] - 2) * sizeof(int));
        memset(returnGrid[i], 0, (gridColSize[i] - 2) * sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i] - 2;
    }
    int j, k, l;
    for (i = 0; i < gridSize - 2; i++) {
        for (j = 0; j < gridColSize[i] - 2; j++) {
            for(k = i; k <= i + 2 && k < gridSize; k++) {
                for (l = j; l <= j + 2 && l < gridColSize[k]; l++) {
                    if (grid[k][l] > returnGrid[i][j]) {
                        returnGrid[i][j] = grid[k][l];
                    }
                }
            }
        }
    }
    return returnGrid;
}