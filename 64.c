int minPathSum(int** grid, int gridSize, int* gridColSize) {
    for (int i = gridSize - 1; i >= 0; i--) {
        for (int j = *gridColSize - 1; j >= 0; j--) {
            if (i < gridSize - 1 && j < *gridColSize - 1) {
                if (grid[i + 1][j] > grid[i][j + 1]) {
                    grid[i][j] += grid[i][j + 1];
                } else {
                    grid[i][j] += grid[i + 1][j];
                }
            } else if (i < gridSize - 1) {
                grid[i][j] += grid[i + 1][j];
            } else if (j < *gridColSize - 1) {
                grid[i][j] += grid[i][j + 1];
            }
        }
    }
    return grid[0][0];
}