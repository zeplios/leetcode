char* itoa(int i) {
    char* res = malloc(20);
    int pos = 19;
    res[pos--] = '\0';
    if (i == 0) {
        res[pos--] = '0';
    }
    while (i != 0) {
        res[pos--] = i % 10 + '0';
        i /= 10;
    }
    return res+pos+1;
}
char* getHint(char* secret, char* guess) {
    int count[10];
    memset(count, 0, 10 * sizeof(int));
    
    int len = strlen(secret), i, bull = 0, cow = 0;
    for (i = 0 ; i < len ; i++) {
        if (secret[i] == guess[i]) {
            bull++;
        } else {
            count[secret[i] - '0']++;
        }
    }
    for (i = 0 ; i < len ; i++) {
        if (secret[i] != guess[i] && count[guess[i] - '0'] > 0) {
            count[guess[i] - '0']--;
            cow++;
        }
    }
    char *bullstr = itoa(bull), *cowstr = itoa(cow);
    int bulllen = strlen(bullstr), cowlen = strlen(cowstr);
    char * res = malloc(bulllen + cowlen + 3);
    memcpy(res, bullstr, bulllen);
    res[bulllen] = 'A';
    memcpy(res+bulllen+1, cowstr, cowlen);
    res[bulllen+cowlen+1] = 'B';
    res[bulllen+cowlen+2] = '\0';
    return res;
}
