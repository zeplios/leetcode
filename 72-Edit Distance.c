int minDistance(char* word1, char* word2) {
    const int DOWN = 0;
    const int RIGHT = 1;
    const int ROUND = 2;
    
    int d, k, M = strlen(word1), N = strlen(word2), state;
    int* V1 = malloc(sizeof(int) * (M+N+2)); // +2 in case of empty string
    int* V2 = malloc(sizeof(int) * (M+N+2));
    int OS = N+1; // offset
    V1[1+OS] = 0;

	int limit = M > N ? M : N;
    for (d = 0 ; d < limit ; d++) {
    	int s = -d > -N ? -d : -N;
    	int e = d > M ? M : d;
        for (k = s ; k <= e ; k += 1) {
            // down or right?
            if (k == -d) {
                state = DOWN;
            } else if (k == d) {
                state = RIGHT;
            } else {
                if (k < d - 1 && V1[k - 1 + OS] < V1[k + 1 + OS] && V1[k + OS] < V1[k + 1 + OS]) {
                    state = DOWN;
                } else if (k > -d + 1 && V1[k - 1 + OS] > V1[k + OS]) {
                    state = RIGHT;
                } else {
                    state = ROUND;
                }
            }
            
            int xStart, yStart;
            if (state == DOWN) {
                xStart = V1[k + 1 + OS];
            } else if (state == RIGHT) {
                xStart = V1[k - 1 + OS] + 1;
            } else {
                xStart = V1[k + OS] + 1;
            }
            yStart = xStart - k;
            
            int xEnd = xStart;
            int yEnd = yStart;
            
            int snake = 0;
            while (xEnd < M && yEnd < N && word1[xEnd] == word2[yEnd]) {
                xEnd++;
                yEnd++;
                snake++;
            }
            
            V2[k + OS] = xEnd;
            
            if (xEnd >= M && yEnd >= N) {
                return d;
            }
        }
        int *V = V1;
        V1 = V2;
        V2 = V;
    }
    return d;
}