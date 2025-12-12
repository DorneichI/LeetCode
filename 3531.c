int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    int* top = malloc(n * sizeof(int));
    int* left = malloc(n * sizeof(int));
    int* right = malloc(n * sizeof(int));
    int* bottom = malloc(n * sizeof(int));
    int i;
    int count = 0;
    for (i = 0; i < n; i++) {
        top[i] = n;
        left[i] = n;
    }
    memset(right, 0, n * sizeof(int));
    memset(bottom, 0, n * sizeof(int));
    for (i = 0; i < buildingsSize; i++) {
        if (buildings[i][0] < top[buildings[i][1] - 1]) top[buildings[i][1] - 1] = buildings[i][0];
        if (buildings[i][0] > bottom[buildings[i][1] - 1]) bottom[buildings[i][1] - 1] = buildings[i][0];
        if (buildings[i][1] < left[buildings[i][0] - 1]) left[buildings[i][0] - 1] = buildings[i][1];
        if (buildings[i][1] > right[buildings[i][0] - 1]) right[buildings[i][0] - 1] = buildings[i][1];
    }
    for (i = 0; i < buildingsSize; i++) {
        if (buildings[i][0] > top[buildings[i][1] - 1] && buildings[i][0] < bottom[buildings[i][1] - 1] && buildings[i][1] > left[buildings[i][0] - 1] && buildings[i][1] < right[buildings[i][0] - 1]) count++;
    }
    free(top);
    free(left);
    free(right);
    free(bottom);
    return count;
}