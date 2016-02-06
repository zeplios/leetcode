/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int hashcode(char *s) {
	// All airports are represented by three capital letters
	return ((s[0] - 'A') << 10) | ((s[1] - 'A') << 5) | (s[2] - 'A'); 
}

char* rebuild(int code) {
	char *s = malloc(4);
	s[0] = ((code >> 10) & 0x1F) + 'A';
	s[1] = ((code >> 5) & 0x1F) + 'A';
	s[2] = (code & 0x1F) + 'A';
	s[3] = '\0';
	return s; 
}

void swap(int nums[][2], int i, int j) {
	if (i == j) {
		return;
	}
	int n0 = nums[i][0], n1 = nums[i][1];
	nums[i][0] = nums[j][0];
	nums[i][1] = nums[j][1];
	nums[j][0] = n0;
	nums[j][1] = n1;
}

void quicksort(int nums[][2], int start, int end) {
    if (start >= end) return;
    int i = start-1, j, tmp;
    for (j = start ; j < end ; j++) {
        if (nums[j][0] == nums[end][0] && nums[j][1] < nums[end][1]) {
            i++;
            swap(nums, i, j);
        }
    }
    i++;
    swap(nums, i, j);
    quicksort(nums, start, i-1);
    quicksort(nums, i+1, end);
}

// @tickets - tickets marked by hashcode
// @ticketsUsed - whether a ticket is used
// @ticketsCount - total tickets
// @usedCount - how many tickets are used, usedCount==ticketsCount means all tickets are used
// @startCode - the hashcode of the current city
// @result - store the result
bool resolve(int tickets[][2], bool *ticketsUsed, int ticketsCount, int usedCount, int startCode, int *result) {
	if (usedCount == ticketsCount) {
		return true;
	}
    int i;
    for (i = 0 ; i < ticketsCount ; i++) {
    	if (!ticketsUsed[i] && tickets[i][0] == startCode) {
    		ticketsUsed[i] = true;
    		result[usedCount+1] = tickets[i][1];
    		int size = resolve(tickets, ticketsUsed, ticketsCount, usedCount+1, tickets[i][1], result);
    		if (size > 0) {
    			return true;
			}
    		ticketsUsed[i] = false;
		}
	}
	return false;
}

char** findItinerary(char*** tickets, int ticketsRowSize, int ticketsColSize, int* returnSize) {
    int ticketsCode[ticketsRowSize][ticketsColSize], i;
    bool ticketsUsed[ticketsRowSize];
    int resultCode[ticketsRowSize+1];
    char **res = malloc((ticketsRowSize+1) * sizeof(char*));
    if (ticketsRowSize == 0) {
        (* returnSize) = 0;
        return res;
    }
    
    // handle string is so complex in c, so convert to int by hash.
    for (i = 0 ; i < ticketsRowSize ; i++) {
    	ticketsCode[i][0] = hashcode(tickets[i][0]);
    	ticketsCode[i][1] = hashcode(tickets[i][1]);
    	ticketsUsed[i] = false;
	}
	// sort by lexical order
	quicksort(ticketsCode, 0, ticketsRowSize-1);
	resultCode[0] = hashcode("JFK");
	resolve(ticketsCode, ticketsUsed, ticketsRowSize, 0, hashcode("JFK"), resultCode);
	
	// rebuild from hashcode to string
	for (i = 0 ; i < ticketsRowSize+1 ; i++) {
		res[i] = rebuild(resultCode[i]);
	}
	// resultSize must be ticketsRowSize+1
	(* returnSize) = i;
	return res;
}
