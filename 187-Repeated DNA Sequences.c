typedef unsigned char byte;
int decode(char a) {
	switch(a){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		default: return 0;
	}
}

char **findRepeatedDnaSequences(char *input, int *outputSize) {
	int size = strlen(input), i, j, k;
	printf("%d", size);
	char **out = malloc(1000);
	*outputSize = 0;
	if (size <= 10) {
		return NULL;
	}
	int tagSize = (1 << 20) / 8;
	byte tag[tagSize];
	byte dup[tagSize];
	memset(tag, 0, tagSize);
	memset(dup, 0, tagSize);
	int hash = 0;
	for (i = 0 ; i <= 8 ; i++) {
		hash = (hash << 2) | decode(input[i]);
	}
	
	for (i = 9 ; i < size ; i++) {
		hash = ((hash & 0x03ffff) << 2) | decode(input[i]);
		int indexOfArr = hash / 8;
		int indexOfByte = hash % 8;
		if (tag[indexOfArr] & (1 << indexOfByte) && (dup[indexOfArr] & (1 << indexOfByte)) == 0) {
			out[*outputSize] = malloc(11);
			memcpy(out[*outputSize], input+i-9, 10);
			out[*outputSize][10] = '\0';
			(*outputSize)++;
			dup[indexOfArr] |= (1 << indexOfByte);
		} else {
			tag[indexOfArr] |= (1 << indexOfByte);
		}
	}
    if ((*outputSize) == 0) {
        return NULL;
    }
    return out;
}