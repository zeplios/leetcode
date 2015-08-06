/**
 * #define NEIGHBORS_MAX_SIZE 100
 * struct UndirectedGraphNode {
 *     int label;
 *     struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
 *     int neighborsCount;
 * };
 */
struct HashNode {
    struct UndirectedGraphNode * key;
    struct UndirectedGraphNode * value;
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

struct HashNode* hashmap_get(struct HashTable* table, struct UndirectedGraphNode * key) {
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
void hashmap_set(struct HashTable* table, struct UndirectedGraphNode * key, struct UndirectedGraphNode * value) {
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
struct UndirectedGraphNode *recurClone(struct UndirectedGraphNode *graph, struct HashTable* table) {
    if (graph == NULL) return NULL;
    struct HashNode * node = hashmap_get(table, graph);
    if (node != NULL) return node->value;
    struct UndirectedGraphNode * cur = malloc(sizeof(struct UndirectedGraphNode));
    cur->label = graph->label;
    cur->neighborsCount = graph->neighborsCount;
    hashmap_set(table, graph, cur);
    int i;
    for (i = 0 ; i < cur->neighborsCount ; i++) {
        cur->neighbors[i] = recurClone(graph->neighbors[i], table);
    }
    return cur;
}
struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph) {
    struct HashTable* table = hashmap_create(1000);
    return recurClone(graph, table);
}