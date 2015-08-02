bool existHelper(char** board, int rsize, int csize, char* word, int x, int y, bool** walked) {
    if (*word == '\0') {
        return true;
    }
    if (x > 0 && board[x-1][y] == *word && !walked[x-1][y]) {
        walked[x-1][y] = true;
        if (existHelper(board, rsize, csize, word+1, x-1, y, walked)) {
            return true;
        }
        walked[x-1][y] = false;
    }
    if (y > 0 && board[x][y-1] == *word && !walked[x][y-1]) {
        walked[x][y-1] = true;
        if (existHelper(board, rsize, csize, word+1, x, y-1, walked)) {
            return true;
        }
        walked[x][y-1] = false;
    }
    if (x < rsize - 1 && board[x+1][y] == *word && !walked[x+1][y]) {
        walked[x+1][y] = true;
        if (existHelper(board, rsize, csize, word+1, x+1, y, walked)) {
            return true;
        }
        walked[x+1][y] = false;
    }
    if (y < csize - 1 && board[x][y+1] == *word && !walked[x][y+1]) {
        walked[x][y+1] = true;
        if (existHelper(board, rsize, csize, word+1, x, y+1, walked)) {
            return true;
        }
        walked[x][y+1] = false;
    }
    return false;
}
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    bool** walked = malloc(sizeof(bool*) * boardRowSize);
    int i, j;
    for (i = 0 ; i < boardRowSize ; i++) {
        walked[i] = malloc(sizeof(bool) * boardColSize);
        for (j = 0 ; j < boardColSize ; j++) {
            walked[i][j] = false;
        }
    }
    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++) {
            if (board[i][j] == *word) {
                walked[i][j] = true;
                if (existHelper(board, boardRowSize, boardColSize, word+1, i, j, walked)) {
                    return true;
                }
                walked[i][j] = false;
            }
        }
    }
    return false;
}