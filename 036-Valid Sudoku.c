bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int a[9], b[9], c[9];
    memset(a, 0, 9*sizeof(int));
    memset(b, 0, 9*sizeof(int));
    memset(c, 0, 9*sizeof(int));
    
    int i, j, k;
    for (i = 0 ; i < 9 ; i++) {
        for (j = 0 ; j < 9 ; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '0';
            if (a[i] & (1 << num)) {
                return false;
            } else {
                a[i] |= (1 << num);
            }
            if (b[j] & (1 << num)) {
                return false;
            } else {
                b[j] |= (1 << num);
            }
            int index = (j / 3) * 3 + (i / 3);
            if (c[index] & (1 << num)) {
                return false;
            } else {
                c[index] |= (1 << num);
            }
        }
    }
    return true;
}