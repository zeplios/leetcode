int minimumTotal(int **triangle, int numRows) {
    if (numRows <= 0) {
        return 0;
    }
    int i = 0, j = 0;
    int min[numRows];
    min[0] = triangle[i][j];
    for (i = 1 ; i < numRows ; i++) {
        min[i] = min[i-1] + triangle[i][i];
        for (j = i - 1 ; j > 0 ; j--) {
            min[j] = (min[j] > min[j-1] ? min[j-1] : min[j]) + triangle[i][j];
        }
        min[0] = min[0] + triangle[i][0];
    }
    int ret = min[0];
    for (i = 1 ; i < numRows ; i++) {
        if (min[i] < ret) {
            ret = min[i];
        }
    }
    return ret;
}
