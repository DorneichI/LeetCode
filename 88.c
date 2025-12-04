void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* nums1Copy = malloc(m * sizeof(int));
    int i, j, k;
    for (i = 0; i < m; i++) {
        nums1Copy[i] = nums1[i];
    }
    i = 0;
    j = 0;
    k = 0;
    while (i < m && j < n) {
        if (nums1Copy[i] < nums2[j]) nums1[k++] = nums1Copy[i++];
        else nums1[k++] = nums2[j++];
    }
    while (i < m) nums1[k++] = nums1Copy[i++];
    while (j < n) nums1[k++] = nums2[j++];
}