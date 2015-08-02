int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int net[gasSize+1];
    int i;
    for (i = 0 ; i < gasSize ; i++) {
        net[i] = gas[i] - cost[i];
    }
    int sum = net[0], min = net[0], minindex = 0;
    for (i = 1 ; i < gasSize ; i++) {
        sum += net[i];
        if (sum < min) {
            min = sum;
            minindex = i;
        }
    }
    if (sum < 0) {
        return -1;
    } else {
        return (minindex + 1) % gasSize;
    }
}