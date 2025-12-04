int countCollisions(char* directions) {
    int stopped = -1;
    int collisions = 0;
    int right = 0;
    for (int i = 0; directions[i] != '\0'; i++) {
        if (directions[i] == 'L' && stopped == 0) {
            collisions += right + 1;
            right = 0;
        } else if (directions[i] == 'S') {
            collisions += right;
            right = 0;
            stopped = 0;
        } else if (directions[i] == 'R') {
            stopped = 0;
            right++;
        }
    }
    return collisions;
}