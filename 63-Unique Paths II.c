int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int m = obstacleGridRowSize, n = obstacleGridColSize;
    int i, j;
    for (i = 0 ; i < m ; i++) {
        for (j = 0 ; j < n ; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;
            } else if (i == 0 && j == 0) {
                obstacleGrid[i][j] = 1;
            } else if (i == 0) {
                obstacleGrid[i][j] = obstacleGrid[i][j-1];
            } else if (j == 0) {
                obstacleGrid[i][j] = obstacleGrid[i-1][j];
            } else {
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
    }
    return obstacleGrid[m-1][n-1];
}