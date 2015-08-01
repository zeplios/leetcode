int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0 || pricesSize == 1) {
		return 0;
	}
	// max profit before or equal the i th day
	int before[pricesSize];
	// max profit after or equal the i th day
	int after[pricesSize];
    int lastmax = 0, newmax = 0, i;
    before[0] = 0;
    after[pricesSize - 1] = 0;
    for (i = 1 ; i < pricesSize ; i++) {
        newmax += prices[i] - prices[i-1];
        lastmax = newmax > lastmax ? newmax : lastmax;
        newmax = newmax > 0 ? newmax : 0;
        before[i] = lastmax;
    }
    lastmax = 0, newmax = 0;
    for (i = pricesSize - 1 ; i > 0 ; i--) {
        newmax += prices[i] - prices[i-1];
        lastmax = newmax > lastmax ? newmax : lastmax;
        newmax = newmax > 0 ? newmax : 0;
        after[i-1] = lastmax;
    }
    int max = 0;
    for (i = 0 ; i < pricesSize ; i++) {
        int sum = before[i] + after[i];
        max = sum > max ? sum : max;
    }
    return max;
}