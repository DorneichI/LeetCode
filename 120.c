int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int** path = malloc(triangleSize * sizeof(int*));
    int* row = malloc(1 * sizeof(int));
    row[0] = triangle[0][0];
    path[0] = row;
    for (int i = 1; i < triangleSize; i++) {
        row = malloc((i + 1) * sizeof(int));
        path[i] = row;
        for (int j = 0; j <= i; j++) {
            if (j == 0) path[i][j] = path[i - 1][j] + triangle[i][j];
            else if (j == i) path[i][j] = path[i - 1][j - 1] + triangle[i][j];
            else if (path[i - 1][j] > path[i - 1][j - 1]) path[i][j] =  path[i - 1][j - 1] + triangle[i][j];
            else path[i][j] = path[i - 1][j] + triangle[i][j];
        }
    }
    int min = path[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++) {
        if (path[triangleSize - 1][i] < min) min = path[triangleSize - 1][i];
    }
    return min;
}