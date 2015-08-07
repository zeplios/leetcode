/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */
struct HashNode {
    double key;
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

struct HashNode* hashmap_get(struct HashTable* table, double key) {
    int hash = (int)key % table->bucketSize;
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
struct HashNode* hashmap_set(struct HashTable* table, double key, int value) {
    int hash = (int)key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    struct HashNode* node = table->buckets[hash];
    if (node == NULL || node->key > key) {
    	struct HashNode * tmp = malloc(sizeof(struct HashNode));
    	tmp->key = key;
    	tmp->value = value;
    	tmp->next = node; // node != NULL ? node : NULL
    	table->buckets[hash] = tmp;
    	return tmp;
	}
	
	if (node->key == key) {
		node->value = value;
		return node;
	}

	while (node->next != NULL && node->next->key < key) {
		node = node->next;
	}
	if (node->next != NULL && node->next->key == key) {
		node->next->value = value;
		return node->next;
	}
	struct HashNode * tmp = malloc(sizeof(struct HashNode));
	tmp->key = key;
	tmp->value = value;
	tmp->next = node->next;
	node->next = tmp;
	return tmp;
}
int maxPoints(struct Point* points, int pointsSize) {
    int maxp = 0, i, j;
    for (i = 0 ; i < pointsSize ; i++) {
        struct HashTable * table = hashmap_create(pointsSize);
        int dup = 0;
        int max = 0;
        for (j = i+1 ; j < pointsSize ; j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                dup++;
                continue;
            }
            int dx = points[j].x - points[i].x;
            int dy = points[j].y - points[i].y;
            double k = (dx != 0 ? dy * 1.0 / dx : INT_MAX);
            struct HashNode * node = hashmap_get(table, k);
            if (node != NULL) node->value++;
            else node = hashmap_set(table, k, 1);
            max = max > node->value ? max : node->value;
        }
        maxp = maxp > 1 + max + dup ? maxp : 1 + max + dup;
    }
    return maxp;
}