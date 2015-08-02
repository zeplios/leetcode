/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool existHelper(char** board, int rsize, int csize, char* word, int x, int y, bool** walked) {
    if (*word == '\0') {
        return true;
    }
    if (x > 0 && board[x-1][y] == *word && !walked[x-1][y]) {
        walked[x-1][y] = true;
        if (existHelper(board, rsize, csize, word+1, x-1, y, walked)) {
        	walked[x-1][y] = false;
            return true;
        }
        walked[x-1][y] = false;
    }
    if (y > 0 && board[x][y-1] == *word && !walked[x][y-1]) {
        walked[x][y-1] = true;
        if (existHelper(board, rsize, csize, word+1, x, y-1, walked)) {
        	walked[x][y-1] = false;
            return true;
        }
        walked[x][y-1] = false;
    }
    if (x < rsize - 1 && board[x+1][y] == *word && !walked[x+1][y]) {
        walked[x+1][y] = true;
        if (existHelper(board, rsize, csize, word+1, x+1, y, walked)) {
        	walked[x+1][y] = false;
            return true;
        }
        walked[x+1][y] = false;
    }
    if (y < csize - 1 && board[x][y+1] == *word && !walked[x][y+1]) {
        walked[x][y+1] = true;
        if (existHelper(board, rsize, csize, word+1, x, y+1, walked)) {
        	walked[x][y+1] = false;
            return true;
        }
        walked[x][y+1] = false;
    }
    return false;
}
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {
    char** res = malloc(sizeof(char*) * wordsSize);
    (* returnSize) = 0;
    
    bool** walked = malloc(sizeof(bool*) * boardRowSize);
    int i, j, k;
    for (i = 0 ; i < boardRowSize ; i++) {
        walked[i] = malloc(sizeof(bool) * boardColSize);
        for (j = 0 ; j < boardColSize ; j++) {
            walked[i][j] = false;
        }
    }
    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++) {
            for (k = 0 ; k < wordsSize ; k++) {
                char* word = words[k];
                if (board[i][j] == *word) {
                    walked[i][j] = true;
                    if (existHelper(board, boardRowSize, boardColSize, word+1, i, j, walked)) {
                        res[(* returnSize)++] = word;
                        *word -= 'a'; // won't search again
                    }
                    walked[i][j] = false;
                }
            }
        }
    }
    for (i = 0 ; i < (* returnSize) ; i++) {
        res[i][0] += 'a';
    }
    for (i = 0 ; i < (* returnSize) ; i++) {
        for (j = i+1 ; j < (* returnSize) ; j++) {
            if (strcmp(res[i], res[j]) == 0) {
                res[j] = res[(* returnSize)-1];
                (* returnSize)--;
                j--;
            }
        }
    }
    return res;
}