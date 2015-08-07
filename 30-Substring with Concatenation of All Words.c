/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode** buckets;
    int bucketSize;
};

struct HashTable* hashmap_create(int size) {
	struct HashTable * table = malloc(sizeof(struct HashTable));
	table->bucketSize = size;
	table->buckets = malloc(sizeof(struct HashTable *) * size);
	memset(table->buckets, 0, sizeof(struct HashTable *) * size);
	return table;
}

int stringhash(char* s, int l) {
    unsigned int h1 = 378551;
    unsigned int h2 = 63689;
    
    unsigned int i, j, hash = 1;
    while (l--) {
        hash *= h2;
        hash += *s;
        h2 *= h1;
        s++;
    }
    
    return hash & 0x7FFFFFFF;
}

struct HashNode* hashmap_get(struct HashTable* table, int key) {
    int hash = key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    struct HashNode* node = table->buckets[hash];
    while(node != NULL && node->key <= key) {
        if(node->key == key) {
        	return node;
		}
        node = node->next;
    }
    return NULL;
}
void hashmap_set(struct HashTable* table, int key, int value) {
    int hash = key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    struct HashNode* node = table->buckets[hash];
    if (node == NULL || node->key > key) {
    	struct HashNode * tmp = malloc(sizeof(struct HashNode));
    	tmp->key = key;
    	tmp->value = value;
    	tmp->next = node; // node != NULL ? node : NULL
    	table->buckets[hash] = tmp;
    	return;
	}
	
	if (node->key == key) {
		node->value = value;
		return;
	}

	while (node->next != NULL && node->next->key < key) {
		node = node->next;
	}
	if (node->next != NULL && node->next->key == key) {
		node->next->value = value;
		return;
	}
	struct HashNode * tmp = malloc(sizeof(struct HashNode));
	tmp->key = key;
	tmp->value = value;
	tmp->next = node->next;
	node->next = tmp;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int* res = malloc(sizeof(int) * 10000);
    (*returnSize) = 0;
    if (wordsSize == 0) return res;
    
    struct HashTable * table = hashmap_create(wordsSize * 2);
    int i, l1 = strlen(s), l2 = strlen(words[0]);
    int hashs[wordsSize], hashvals[wordsSize];
    for (i = 0 ; i < wordsSize ; i++) {
        hashs[i] = stringhash(words[i], l2);
        struct HashNode * node = hashmap_get(table, hashs[i]);
        if (node != NULL) {
            node->value++;
        } else {
            hashmap_set(table, hashs[i], 1);
        }
    }
    for (i = 0 ; i < wordsSize ; i++) {
        hashvals[i] = hashmap_get(table, hashs[i])->value;
    }
    
    char* start = s;
    while (l1 >= l2 * wordsSize) {
        for (i = 0 ; i < wordsSize ; i++) {
            hashmap_set(table, hashs[i], hashvals[i]);
        }
        int ws = wordsSize;
        while (ws--) {
            int key = stringhash(start + (wordsSize - ws - 1) * l2, l2);
            struct HashNode * node = hashmap_get(table, key);
            if (node != NULL && node->value > 0) {
                node->value--;
                if (ws == 0) {
                    res[(*returnSize)++] = start-s;
                }
            } else {
                break;
            }
        }
        start++;
        l1--;
    }
    return res;
}