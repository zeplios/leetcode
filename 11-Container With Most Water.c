int area(int* height, int l, int r) {
    return (r-l) * (height[l] > height[r] ? height[r] : height[l]);
}
int maxArea(int* height, int heightSize) {
    if (heightSize <= 1) return 0;
    int start = 0, end = heightSize - 1;
    int max = 0;
    while (start < end) {
        int narea = area(height, start, end);
        if (narea > max) {
            max = narea;
        }
        
        if (height[start] > height[end]) {
            int min = height[end];
            while (start < end && height[--end] <= min);
        } else {
            int min = height[start];
            while (start < end && height[++start] <= min);
        }
    }
    return max;
}