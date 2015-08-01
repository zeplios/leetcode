bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start = 0, end = matrixRowSize;
    int mid = (start + end) / 2;
    if (target < matrix[0][0] || target > matrix[matrixRowSize-1][matrixColSize-1]) return false;
    while (true) {
        if (matrix[mid][0] == target) return true;
        if (mid == matrixRowSize - 1 && matrix[mid][0] < target) break;
        if (matrix[mid][0] < target && target < matrix[mid+1][0]) break;
        if (matrix[mid][0] > target) {
            end = mid;
            mid = (mid + start) / 2;
        } else {
            start = mid;
            mid = (mid + end) / 2;
        }
    }
    int rowNum = mid;
    start = 0;
    end = matrixColSize;
    mid = (start + end) / 2;
    while (true) {
        if (matrix[rowNum][mid] == target) return true;
        if (mid == matrixColSize - 1 && matrix[rowNum][mid] < target) return false;
        if (matrix[rowNum][mid] < target && target < matrix[rowNum][mid+1]) return false;
        int premid = mid;
        if (matrix[rowNum][mid] > target) {
            end = mid;
            mid = (mid + start) / 2;
        } else {
            start = mid;
            mid = (mid + end) / 2;
        }
        if (premid == mid) {
        	break;
		}
    }
    return false;
}