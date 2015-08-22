int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (divisor == 1) return dividend;
    if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;
    if (divisor == INT_MIN) return dividend == INT_MIN;
    
	int res = 0, sum = 0, time, tmp;
    bool neg = false;
    if (divisor < 0) {
        divisor = -divisor;
        neg = !neg;
    }
    if (dividend < 0) {
    	if (dividend == INT_MIN) {
    		dividend += divisor;
    		res++;
		}
        dividend = -dividend;
        neg = !neg;
    }
    
    while (sum <= dividend - divisor) { // account for overflow, use - instand of sum + divisor <= dividend
        tmp = divisor;
        time = 1;
        while (sum <= dividend - tmp) {
            sum += tmp;
            res += time;
            tmp += tmp;
            time += time;
        }
    }
    return neg ? -res : res;
}