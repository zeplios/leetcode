double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    // n may be the max negative number, -n will overflow
    if (n < -1024 || n > 0) {
    	int halfpower = n / 2;
    	double half = myPow(x, halfpower);
    	return half * half * myPow(x, n-halfpower*2);
	}
    else 
        return 1 / myPow(x, -n);
}