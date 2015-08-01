bool isHappy(int n) {
    bool appear[1000];
    memset(appear, 0, sizeof(bool) * 1000);
    while (1) {
    	int sum = 0, m;
    	while (n) {
    		m = n % 10;
	    	sum += m * m;
	    	n = n / 10;
		}
		if (sum == 1) {
			return true;
		}
		if (appear[sum] && sum != 1) {
			return false;
		}
		appear[sum] = true;
		n = sum;
	}
}