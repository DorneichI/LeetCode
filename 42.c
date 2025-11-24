int trap(int* height, int heightSize) {
    int i;
    int maxIndex = 0;
    for (i = 0; i < heightSize; i++) {
        if (height[i] > height[maxIndex]) {
            maxIndex = i;
        }
    }
    int sum = 0;
    int otherHeight = 0;
    for (int i = 0; i < maxIndex; i++) {
        if (otherHeight >= height[i]) {
            sum += otherHeight - height[i];
        } else {
            otherHeight = height[i];
        }
    }
    otherHeight = 0;
    for (int i = heightSize - 1; i > maxIndex; i--) {
        if (otherHeight >= height[i]) {
            sum += otherHeight - height[i];
        } else {
            otherHeight = height[i];
        }
    }
    return sum;
}