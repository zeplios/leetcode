int lengthOfLastWord(char* s) {
    int count = 0;
    bool newword = true;
    while (*s != '\0') {
        if (*s == ' ') {
            newword = true;
        } else {
            if (newword) {
                newword = false;
                count = 0;
            }
            count++;
        }
        s++;
    }
    return count;
}