bool midsearch(int** matrix, int startx, int endx, int starty, int endy, int target) {
    if (startx > endx || starty > endy) {
        return false;
    }
    if (startx == endx && starty == endy && matrix[startx][starty] != target) {
        return false;
    }
    int midx = (startx + endx) / 2;
    int midy = (starty + endy) / 2;
    if (matrix[midx][midy] == target) {
        return true;
    } else if (matrix[midx][midy] > target) {
        return midsearch(matrix, startx, midx-1, starty, midy-1, target)
            || midsearch(matrix, midx, endx, starty, midy-1, target)
            || midsearch(matrix, startx, midx-1, midy, endy, target);
    } else {
        return midsearch(matrix, midx+1, endx, midy+1, endy, target)
            || midsearch(matrix, midx+1, endx, starty, midy, target)
            || midsearch(matrix, startx, midx, midy+1, endy, target);
    }
}
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return midsearch(matrix, 0, matrixRowSize - 1, 0, matrixColSize - 1, target);
}