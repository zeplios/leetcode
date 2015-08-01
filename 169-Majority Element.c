int majorityElement(int num[], int n) {
	int selfstart = 0, i;
	for (i = 1 ; i < n - 1 ; i++) {
		if (num[selfstart] != num[i]) {
			if (selfstart + 1 == i) {
				selfstart = ++i;
			} else {
				num[i] = num[selfstart];
				selfstart += 2;
			}
		}
	}
    return num[selfstart];
}