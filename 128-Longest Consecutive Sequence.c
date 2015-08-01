struct I2iHashNode {
    int key;
    int value;
    struct I2iHashNode* next;
};

struct I2iHashTable {
    struct I2iHashNode** buckets;
    int bucketSize;
};

struct I2iHashTable* hashmap_create(int size) {
	struct I2iHashTable * table = malloc(sizeof(struct I2iHashTable));
	table->bucketSize = size;
	table->buckets = malloc(sizeof(struct I2iHashTable *) * size);
	memset(table->buckets, 0, sizeof(struct I2iHashTable *) * size);
	return table;
}

struct I2iHashNode* hashmap_get(struct I2iHashTable* table, int key) {
    int hash = key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    struct I2iHashNode* node = table->buckets[hash];
    while(node != NULL && node->key <= key) {
        if(node->key == key) {
        	return node;
		}
        node = node->next;
    }
    return NULL;
}
void hashmap_set(struct I2iHashTable* table, int key, int value) {
    int hash = key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    struct I2iHashNode* node = table->buckets[hash];
    if (node == NULL || node->key > key) {
    	struct I2iHashNode * tmp = malloc(sizeof(struct I2iHashNode));
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
	struct I2iHashNode * tmp = malloc(sizeof(struct I2iHashNode));
	tmp->key = key;
	tmp->value = value;
	tmp->next = node->next;
	node->next = tmp;
}

int longestConsecutive(int* nums, int numsSize) {
    struct I2iHashTable* table = hashmap_create(numsSize);
    int i, max = 0;
    for (i = 0 ; i < numsSize ; i++) {
        if (hashmap_get(table, nums[i]) != NULL) {
            continue;
        }
        struct I2iHashNode * pre = hashmap_get(table, nums[i]-1);
        struct I2iHashNode * nxt = hashmap_get(table, nums[i]+1);
        
        int newlen = (pre != NULL ? pre->value : 0) + (nxt != NULL ? nxt->value : 0) + 1;
        if (pre != NULL) {
            hashmap_set(table, nums[i]-pre->value, newlen);
        }
        if (nxt != NULL) {
            hashmap_set(table, nums[i]+nxt->value, newlen);
        }
        hashmap_set(table, nums[i], newlen);
        if (newlen > max) {
            max = newlen;
        }
    }
    return max;
}