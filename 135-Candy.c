int candy(int* ratings, int ratingsSize) {
    int num[ratingsSize];
    memset(num, 0, sizeof(int)*ratingsSize);
    int max = 0;
    int i, j;
    if (ratingsSize <= 1) return ratingsSize;
    for (i = 0 ; i < ratingsSize ; i++) {
        bool lowerThanLeft = (i < 1 || ratings[i] <= ratings[i-1]);
        bool lowerThanRight = (i >= ratingsSize - 1 || ratings[i] <= ratings[i+1]);
        if (lowerThanLeft && lowerThanRight) {
            int should = 1;
            max += should - num[i];
            num[i] = should;
            for (j = i - 1 ; j >= 0 ; j--) {
                if (ratings[j] > ratings[j+1]) {
                    should++;
                    if (should <= num[j]) {
                        break;
                    }
                    max += should - num[j];
                    num[j] = should;
                } else {
                    break;
                }
            }
            should = 1;
            for (j = i + 1 ; j < ratingsSize ; j++) {
                if (ratings[j] > ratings[j-1]) {
                    should++;
                    if (should <= num[j]) {
                        break;
                    }
                    max += should - num[j];
                    num[j] = should;
                } else {
                    break;
                }
            }
            i = j - 1;
        }
    }
    return max;
}