char* convert(char* s, int numRows) {
    int count = 0, i;
    char *c = s;
    while (*c != '\0') c++;
    count = c - s;
    if (count == 0 || numRows <= 1) return s;
    int regionSize = 2*numRows-2;
    int regions = (count % regionSize == 0) ? count / regionSize : count / regionSize + 1;
    int starts[regions], ends[regions];
    for (i = 0 ; i < regions ; i++) {
        starts[i] = i * regionSize;
        ends[i] = (i+1) * regionSize;
    }
    
    char * res = malloc(count+1);
    int pos = 0, curRow = 0;
    while (pos < count) {
        for (i = 0 ; i < regions ; i++) {
            int index;
            index = starts[i] + curRow;
            if (index >= count) break;
            res[pos++] = s[index];
            if (curRow != 0 && curRow != numRows-1) {
                index = ends[i] - curRow;
                if (index >= count) break;
                res[pos++] = s[index];
            }
        }
        curRow++;
    }
    res[pos] = '\0';
    return res;
}