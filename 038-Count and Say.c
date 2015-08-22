char* countAndSay(int n) {
    char * res = malloc(10000);
    char * oth = malloc(10000);
    int length = 0, olen = 0;
    
    if (n <= 0) {
        res[length] = '\0';
        return res;
    }
    
    int i, j;
    res[length++] = '1';
    for (i = 1 ; i < n ; i++) {
        char pre = res[0];
        int count = 1;
        for (j = 1 ; j < length ; j++) {
            if (res[j] == pre) {
                count++;
                if (count == 10) {
                    oth[olen++] = '1';
                    count = 0;
                }
            } else {
                oth[olen++] = count + '0';
                oth[olen++] = pre;
                pre = res[j];
                count = 1;
            }
        }
        oth[olen++] = count + '0';
        oth[olen++] = pre;
        char * tmp = res;
        res = oth;
        oth = tmp;
        length = olen;
        olen = 0;
        
    }
    res[length] = '\0';
    return res;
}