int countPrimes(int n) {
    bool isPrime[n];
    int i, j;
    for (i = 0 ; i < n ; i++) {
    	isPrime[i] = true;
	}
    isPrime[1] = false;
    for (i = 2 ; i < n ; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (j = 2 ; j < n ; j++) {
            int num = i * j;
            if (num >= n) {
                break;
            }
            isPrime[num] = false;
        }
    }
    int count = 0;
    for (i = 2 ; i < n ; i++) {
    	if (isPrime[i]) {
    		count++;
		}
	}
	return count;
}