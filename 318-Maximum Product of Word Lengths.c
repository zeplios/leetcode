int maxProduct(char** words, int wordsSize) {
    int bitmap[wordsSize], wordslen[wordsSize];
    memset(bitmap, 0, wordsSize * sizeof(int));
    memset(wordslen, 0, wordsSize * sizeof(int));
    int i, j, max = 0;
    for (i = 0 ; i < wordsSize ; i++) {
        char *s = words[i];
        while (*s != '\0') {
            bitmap[i] |= 1 << (*s-'a');
            wordslen[i]++;
            s++;
        }
    }
    
    for (i = 0 ; i < wordsSize ; i++) {
        for (j = i + 1 ; j < wordsSize ; j++) {
            int len = ((bitmap[i] & bitmap[j]) == 0) ? wordslen[i] * wordslen[j] : 0;
            max = max > len ? max : len;
        }
    }
    return max;
}
