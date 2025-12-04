int countCollisions(char* directions) {
    int leftCar = -1; //-1 left, 0 stationary, >=1 right
    int collisions = 0;
    for (int i = 0; directions[i] != '\0'; i++) {
        if (directions[i] == 'L') {
            if (leftCar == 0) {
                collisions += 1;
            } else if (leftCar >= 1) {
                collisions += leftCar + 1;
                leftCar = 0;
            }
        } else if (directions[i] == 'S') {
            if (leftCar == -1) {
                leftCar = 0;
            } else if (leftCar >= 1) {
                collisions += leftCar;
                leftCar = 0;
            }
        } else {
            if (leftCar <= 0) {
                leftCar = 1;
            } else {
                leftCar++;
            }
        }
    }
    return collisions;
}