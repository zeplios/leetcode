void walkaround(int** pass, int maxx, int maxy, int curx, int cury) {
    pass[curx][cury] = 0;
    if (curx < maxx - 1 && pass[curx+1][cury] == 1) {
        walkaround(pass, maxx, maxy, curx+1, cury); // to bottom
    }
    if (cury < maxy - 1 && pass[curx][cury+1] == 1) {
        walkaround(pass, maxx, maxy, curx, cury+1); // to right
    }
    if (curx > 0 && pass[curx-1][cury] == 1) {
        walkaround(pass, maxx, maxy, curx-1, cury); // to top
    }
    if (cury > 0 && pass[curx][cury-1] == 1) {
        walkaround(pass, maxx, maxy, curx, cury-1); // to left
    }
}
int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int** pass = malloc(sizeof(int*)*gridRowSize);
    int count = 0, i, j;
    for (i = 0 ; i < gridRowSize ; i++) {
        pass[i] = malloc(sizeof(int)*gridColSize);
        for (j = 0 ; j < gridColSize ; j++) {
            pass[i][j] = grid[i][j] - '0';
        }
    }
    for (i = 0 ; i < gridRowSize ; i++) {
        for (j = 0 ; j < gridColSize ; j++) {
            if (pass[i][j] == 1) {
                count++;
                walkaround(pass, gridRowSize, gridColSize, i, j);
            }
        }
    }
    return count;
}