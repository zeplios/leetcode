/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
int hashAnagram(char* s) {
    unsigned int h1 = 378551;
    unsigned int h2 = 63689;
    int a[26];
    memset(a, 0, sizeof(int)*26);
    
    while (*s != '\0') {
        a[*s-'a']++;
        s++;
    }
    unsigned int i, j, hash = 1;
    for (i = 0 ; i < 26 ; i++) {
        if (a[i] > 0) {
        	for (j = 0 ; j < a[i] ; j++) {
	        	hash *= h2;
	        	hash += i+1;
			}
        	
		}
        h2 *= h1;
    }
    return hash & 0x7FFFFFFF;
}
char** anagrams(char** strs, int strsSize, int* returnSize) {
    char** res = malloc(sizeof(char*) * 10000);
    (* returnSize) = 0;
    struct I2iHashTable* table = hashmap_create(strsSize);
    int i;
    for (i = 0 ; i < strsSize ; i++) {
        int hash = hashAnagram(strs[i]);
        struct I2iHashNode * node = hashmap_get(table, hash);
        if (node != NULL) {
            if (node->value >= 0) {
                int l = strlen(strs[node->value]);
                res[(* returnSize)] = malloc(l+1);
                memcpy(res[(* returnSize)++], strs[node->value], l+1);
                node->value = -1;
            }
            int l = strlen(strs[i]);
            res[(* returnSize)] = malloc(l+1);
            memcpy(res[(* returnSize)++], strs[i], l+1);
        } else {
            hashmap_set(table, hash, i);
        }
    }
    return res;
}