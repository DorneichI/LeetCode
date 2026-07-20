/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int num = gridSize * gridColSize[0];
    k = k % num;
    int* tmp = malloc(k * sizeof(int));
    int i;
    for (i = 0; i < k; i++) {
        tmp[i] = grid[i / *gridColSize][i % *gridColSize];
        grid[i / gridColSize[i % gridSize]][i % gridColSize[i % gridSize]] = 
        grid[(num - k + i) / gridColSize[i % gridSize]][(num - k + i) % gridColSize[i % gridSize]];
    }
    int temp;
    if (k > 0) {
        for (i = k; i < (gridSize * *gridColSize); i++) {
            temp = tmp[i % k];
            tmp[i % k] = grid[i / *gridColSize][i % *gridColSize];
            grid[i / *gridColSize][i % *gridColSize] = temp;
        }
    }


    *returnSize = gridSize;

    *returnColumnSizes = malloc(gridSize * sizeof(int));
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i < gridSize; i++) {
        (*returnColumnSizes)[i] = gridColSize[i];
    }
    return grid;
}
