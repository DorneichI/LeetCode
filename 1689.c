int minPartitions(char* n) {
    int partitions = 1;
    int c;
    for (int i = 0; (c = n[i]) != '\0'; i++) {
        if (c - '0' > partitions) partitions = c - '0';
    }
    return partitions;
}