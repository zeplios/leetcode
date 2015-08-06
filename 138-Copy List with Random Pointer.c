/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct HashNode {
    struct RandomListNode * key;
    struct RandomListNode * value;
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

struct HashNode* hashmap_get(struct HashTable* table, struct RandomListNode * key) {
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
void hashmap_set(struct HashTable* table, struct RandomListNode * key, struct RandomListNode * value) {
    int hash = (int)key % table->bucketSize;
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
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if (head == NULL) return head;
    struct I2iHashTable* table = hashmap_create(1000);
    struct RandomListNode * start = malloc(sizeof(struct RandomListNode));
    start->label = head->label;
    start->next = NULL;
    hashmap_set(table, head, start);
    struct RandomListNode * sc = start;
    struct RandomListNode * hc = head->next;
    while (hc != NULL) {
        struct RandomListNode * tmp = malloc(sizeof(struct RandomListNode));
        tmp->label = hc->label;
        tmp->next = NULL;
        hashmap_set(table, hc, tmp);
        sc->next = tmp;
        sc = tmp;
        hc = hc->next;
    }
    sc = start;
    hc = head;
    while (hc != NULL) {
        struct HashNode * node = hashmap_get(table, hc->random);
        sc->random = node != NULL ? node->value : NULL;
        hc = hc->next;
        sc = sc->next;
    }
    return start;
}