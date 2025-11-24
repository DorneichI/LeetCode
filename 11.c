int maxArea(int* height, int heightSize) {
    int max = 0;
    for (int i = 0; i < heightSize; i++) {
        if (height[i] == 0) continue;
        int min_dist = (max / height[i]) + i + 1;
        for (int j = min_dist; j < heightSize; j++) {
            if (height[i] < height[j]) {
                max = (max > height[i] * (j - i)) ? max : height[i] * (j - i);
            } else {
                max = (max > height[j] * (j - i)) ? max : height[j] * (j - i);
            }
        }
    }
    return max;
}