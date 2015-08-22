bool isScrambleHelper(char* start1, char* start2, char* s1, char* s2, int length, int*** status) {
	if (length == 1) return *s1 == *s2;
    int times[26], zeroCount = 26, i;
    memset(times, 0, sizeof(int)*26);
    
    if (length == 0) return true;
    if (status[s1-start1][s2-start2][length-1] > 0) {
    	return status[s1-start1][s2-start2][length-1] == 1;
	}
    for (i = 0 ; i < length-1 ; i++) {
        int index1 = s1[i]-'a';
        int index2 = s2[i]-'a';
        times[index1]++;
        if (times[index1] == 1) {
            zeroCount--;
        }
        times[index2]--;
        if (times[index2] == 0) {
            zeroCount++;
        }
        if (zeroCount == 26) {
            bool leftMatch = isScrambleHelper(start1, start2, s1, s2, i+1, status);
            bool rightMatch = isScrambleHelper(start1, start2, s1+i+1, s2+i+1, length-i-1, status);
            if (leftMatch && rightMatch) {
            	status[s1-start1][s2-start2][length-1] = 1;
                return true;
            }
        }
    }
    
    memset(times, 0, sizeof(int)*26);
    zeroCount = 26;
    for (i = 0 ; i < length-1 ; i++) {
        int index1 = s1[i]-'a';
        int index2 = s2[length-1-i]-'a';
        times[index1]++;
        if (times[index1] == 1) {
            zeroCount--;
        }
        times[index2]--;
        if (times[index2] == 0) {
            zeroCount++;
        }
        if (zeroCount == 26) {
            bool leftMatch = isScrambleHelper(start1, start2, s1, s2+length-1-i, i+1, status);
            bool rightMatch = isScrambleHelper(start1, start2, s1+i+1, s2, length-i-1, status);
            if (leftMatch && rightMatch) {
            	status[s1-start1][s2-start2][length-1] = 1;
                return true;
            }
        }
    }
    status[s1-start1][s2-start2][length-1] = 2;
    return false;
}
bool isScramble(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2), i, j, k;
    if (len1 != len2) return false;
    int ***status = malloc(sizeof(int**) * len1);
    for (i = 0 ; i < len1 ; i++) {
    	status[i] = malloc(sizeof(int*) * len1);
    	for (j = 0 ; j < len1 ; j++) {
    		status[i][j] = malloc(sizeof(int) * len1);
    		memset(status[i][j], 0, sizeof(int) * len1);
    	}
	}
    return isScrambleHelper(s1, s2, s1, s2, len1, status);
}