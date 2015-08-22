int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize == 0 || gridColSize == 0) return 0;
    int path[gridRowSize][gridColSize];
    int i, j;
    path[0][0] = grid[0][0];
    for (i = 1 ; i < gridRowSize ; i++) {
        path[i][0] = path[i-1][0] + grid[i][0];
    }
    for (i = 1 ; i < gridColSize ; i++) {
        path[0][i] = path[0][i-1] + grid[0][i];
    }
    for (i = 1 ; i < gridRowSize ; i++) {
        for (j = 1 ; j < gridColSize ; j++) {
            path[i][j] = grid[i][j] + (path[i-1][j] < path[i][j-1] ? path[i-1][j] : path[i][j-1]);
        }
    }
    return path[gridRowSize-1][gridColSize-1];
}