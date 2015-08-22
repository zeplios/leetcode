void merge(int* nums1, int m, int* nums2, int n) {
    int offset = n, i = m + n - 1, j = n - 1;
    for ( ; i >= 0 ; i--) {
        if (j >= 0 && (i - offset < 0 || nums2[j] > nums1[i - offset])) {
            nums1[i] = nums2[j];
            offset--;
            j--;
        } else {
            nums1[i] = nums1[i - offset];
        }
    }
}