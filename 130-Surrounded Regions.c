/* 直接用递归来实现dfs会Runtime Error，用队列比用栈需要的空间应该会少一些 */
void wipe(char** board, int rsize, int csize, bool** walked, int x, int y, int* xq, int* yq, int size) {
    int head = 0, tail = 0;
    board[x][y] = 'X';
    xq[tail] = x; yq[tail++] = y;
    while (tail != head) {
        x = xq[head]; y = yq[head];
        
        if (x > 0 && board[x-1][y] == 'O') {
        	board[x-1][y] = 'X';
            xq[tail] = x-1; yq[tail++] = y; tail %= size;
        }
        if (y > 0 && board[x][y-1] == 'O') {
        	board[x][y-1] = 'X';
            xq[tail] = x; yq[tail++] = y-1; tail %= size;
        }
        if (x < rsize-1 && board[x+1][y] == 'O') {
        	board[x+1][y] = 'X';
            xq[tail] = x+1; yq[tail++] = y; tail %= size;
        }
        if (y < csize-1 && board[x][y+1] == 'O') {
        	board[x][y+1] = 'X';
            xq[tail] = x; yq[tail++] = y+1; tail %= size;
        }
    	head++; head %= size;
    }
}
bool isSurrounded(char** board, int rsize, int csize, bool** walked, int x, int y, int* xq, int* yq, int size) {
	int head = 0, tail = 0;
    bool ret = true;
    walked[x][y] = true;
    xq[tail] = x; yq[tail++] = y;
    while (tail != head) {
        x = xq[head]; y = yq[head];
        if (x == 0 || x == rsize-1 || y == 0 || y == csize-1) {
            ret = false;
        }
        if (x > 0 && walked[x-1][y] == false) {
        	walked[x-1][y] = true;
            xq[tail] = x-1; yq[tail++] = y; tail %= size;
        }
        if (y > 0 && walked[x][y-1] == false) {
        	walked[x][y-1] = true;
            xq[tail] = x; yq[tail++] = y-1; tail %= size;
        }
        if (x < rsize-1 && walked[x+1][y] == false) {
        	walked[x+1][y] = true;
            xq[tail] = x+1; yq[tail++] = y; tail %= size;
        }
        if (y < csize-1 && walked[x][y+1] == false) {
        	walked[x][y+1] = true;
            xq[tail] = x; yq[tail++] = y+1; tail %= size;
        }
        head++; head %= size;
    }
    return ret;
}
void solve(char** board, int boardRowSize, int boardColSize) {
    bool** walked = malloc(sizeof(bool*) * boardRowSize);
    int size = boardRowSize * boardColSize / 2;
    size = size < 2 ? 2 : size;
    int* xq = malloc(sizeof(int) * size);
	int* yq = malloc(sizeof(int) * size);
    int i, j;
    for (i = 0 ; i < boardRowSize ; i++) {
        walked[i] = malloc(sizeof(bool) * boardColSize);
        for (j = 0 ; j < boardColSize ; j++) {
            walked[i][j] = (board[i][j] == 'X'); // assume the 'X' is walked
        }
    }
    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++) {
            if (walked[i][j] == false) {
                if (isSurrounded(board, boardRowSize, boardColSize, walked, i, j, xq, yq, size)) {
                    wipe(board, boardRowSize, boardColSize, walked, i, j, xq, yq, size);
                }
            }
        }
    }
}