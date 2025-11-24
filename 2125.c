int numberOfBeams(char** bank, int bankSize) {
    int totalLasers = 0;
    int countLastRow = 0;
    for (int i = 0; i < bankSize; i++) {
        int countThisRow = 0;
        for (int j = 0; bank[i][j] != '\0'; j++) {
            if (bank[i][j] == '1') {
                countThisRow++;
            }
        }
        if (countThisRow > 0) {
            totalLasers += countThisRow * countLastRow;
            countLastRow = countThisRow;
            countThisRow = 0;
        }
    }
    return totalLasers;
}