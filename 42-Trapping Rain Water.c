int trapmid(int * height, int start, int end) {
    if (start >= end - 1) {
        return 0;
    }
    int bound1 = start, bound2 = end, sum = 0, i = start, j = end;
    while (i < j - 1) {
        if (height[i] < height[j]) {
            i++;
            if (height[i] > height[bound1]) {
                bound1 = i;
            }
        } else {
            j--;
            if (height[j] > height[bound2]) {
                bound2 = j;
            }
        }
    }
    int min_height = height[bound1] > height[bound2] ? height[bound2] : height[bound1];
    for (i = bound1 + 1 ; i < bound2 ; i++) {
        sum += min_height - height[i];
    }
    return sum + trapmid(height, start, bound1) + trapmid(height, bound2, end);
}
int trap(int* height, int heightSize) {
    return trapmid(height, 0, heightSize-1);
}
