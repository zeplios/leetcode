#define MAX(a, b, c) a > b ? (a > c ? a : c) : (b > c ? b : c);
int dp(int* height, int start, int end, int* leftmin, int* rightmin) {
    if (start > end) return 0;
    int i, min = start;
    if (rightmin[start] <= end) min = rightmin[start];
    else if (leftmin[end] >= start) min = leftmin[end];
    else {
        for (i = start + 1 ; i <= end ; i++) {
            if (height[i] < height[min]) {
                min = i;
            }
        }
    }
    int cur = (end-start+1) * height[min];
    int left = dp(height, start, min-1, leftmin, rightmin);
    int right = dp(height, min+1, end, leftmin, rightmin);
    return MAX(cur, left, right);
}
int largestRectangleArea(int* height, int heightSize) {
    if (heightSize <= 0) return 0;
    int * leftmin = calloc(heightSize, sizeof(int));
    int * rightmin = calloc(heightSize, sizeof(int));
    int i;
    leftmin[0] = 0;
    rightmin[heightSize-1] = heightSize-1;
    for (i = 1 ; i < heightSize ; i++) {
        leftmin[i] = height[i] <= height[leftmin[i-1]] ? i : leftmin[i-1];
    }
    for (i = heightSize - 2 ; i >= 0 ; i--) {
        rightmin[i] = height[i] <= height[rightmin[i+1]] ? i : rightmin[i+1];
    }
    return dp(height, 0 ,heightSize-1, leftmin, rightmin);
}