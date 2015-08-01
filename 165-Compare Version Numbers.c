char* delzeros(char *version) {
	int size = strlen(version);
	char *out = malloc(size+1);
	int offset = 0, i;
    int isfirst = 1;
	for (i = 0 ; i < size ; i++) {
		out[i-offset] = version[i];
    	if (version[i] == '.') {
    		isfirst = 1;
    		continue;
		}
		if (isfirst && version[i] == '0') {
			offset++;
			continue;
		}
		isfirst = 0;
	}
	for (i = i - offset ; i >= 0 ; i--) {
		if (out[i - 1] != '.') {
			out[i] = '\0';
			break;
		}
	}
	return out;
}

int compareVersion(char *version1, char *version2){
	char * v1 = delzeros(version1);
	char * v2 = delzeros(version2);
    int dot1 = -1, dot2 = -1, i, j;
    int start1 = 0, start2 = 0;
    int size1 = strlen(v1), size2 = strlen(v2);
    while (1) {
        if (dot1 == size1 && dot2 != size2) {
            return -1;
        }
        if (dot1 != size1 && dot2 == size2) {
            return 1;
        }
        if (dot1 == size1 && dot2 == size2 && dot1 != -1) {
            return 0;
        }
        for (i = dot1 + 1 ; i < size1 ; i++) {
            if (v1[i] == '.') {
                dot1 = i;
                break;
            }
        }
        for (j = dot2 + 1 ; j < size2 ; j++) {
            if (v2[j] == '.') {
                dot2 = j;
                break;
            }
        }
        if (i == size1) {
            dot1 = size1;
        }
        if (j == size2) {
            dot2 = size2;
        }
        if (dot1 - start1 > dot2 - start2) {
            return 1;
        } else if (dot1 - start1 < dot2 - start2) {
            return -1;
        } else {
            for (i = start1, j = start2 ; i < dot1 ; i++, j++) {
                if (v1[i] > v2[j]) {
                    return 1;
                } else if (v1[i] < v2[j]) {
                    return -1;
                }
            }
            start1 = dot1 + 1;
            start2 = dot2 + 1;
        }
    }
}