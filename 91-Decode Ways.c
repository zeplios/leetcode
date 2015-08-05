int numDecodings(char* s) {
    const int MUST = 0; // must help the next number
    const int CAN1 = 1;  // help or not is all ok if prev number is 1
    const int CAN2 = 2;  // help or not is all ok if prev number is 2 or 1
    const int CANNOT = 3; // can't help the next number
    
    int l = strlen(s), i;
    int num[l+1];
    if (l == 0) return 0;
    num[0] = 1;
    int state = CANNOT;
    for (i = 1 ; i <= l ; i++) {
        if ((s[l-i] == '0' || s[l-i] > '2') && state == MUST) {
            return 0;
        }
        if (state == MUST) {
            num[i] = num[i-2];
            state = CANNOT;
        } else if (s[l-i] == '0') {
            num[i] = 0;
            state = MUST;
        } else if (s[l-i] > '6') {
            num[i] = num[i-1];
            state = CAN1;
        } else if (s[l-i] == '1' && (state == CAN1 || state == CAN2)) {
            num[i] = num[i-1] + num[i-2];
            state = CAN2;
        } else if (s[l-i] == '2' && state == CAN2) {
            num[i] = num[i-1] + num[i-2];
            state = CAN2;
        } else if (s[l-i] <= '6') {
            // assert state != MUST
            num[i] = num[i-1];
            state = CAN2;
        }
    }
    return num[l];
}