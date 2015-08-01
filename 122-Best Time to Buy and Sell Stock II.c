！！！用了和第一题不同的方法！！！

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0 || pricesSize == 1) {
		return 0;
	}
	int i;
    int total = 0, lastmax = 0, newmax = 0;
    for (i = 1 ; i < pricesSize ; i++) {
    	newmax += (prices[i] - prices[i-1]);
    	if (newmax > 0 && newmax > lastmax) {
    		lastmax = newmax;
		} else {
			total += lastmax;
			newmax = 0;
			lastmax = 0;
		}
	}
	total += lastmax;
	return total;
}