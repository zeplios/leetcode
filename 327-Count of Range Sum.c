// if n > (upper-lower), time is O(n*(upper-lower)), or O(n^2)
// ----------------------an implentation of HashTable------------------
typedef long K;
typedef long V;
typedef struct HashNode {
    K key;
    V value;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    struct HashNode** buckets;
    int bucketSize;
    int eleCount;
} HashTable;

HashTable* hashtable_create(int size) {
    if (size < 1) size = 1;
    HashTable * table = malloc(sizeof(HashTable));
    table->bucketSize = size;
    table->eleCount = 0;
    table->buckets = malloc(size * sizeof(HashTable *));
    memset(table->buckets, 0, size * sizeof(HashTable *));
    return table;
}

// use HashNode instand of int for NULL returnt
HashNode* hashtable_get(HashTable* table, K key) {
    int hash = key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    HashNode* node = table->buckets[hash];
    while(node != NULL && node->key != key) {
        node = node->next;
    }
    return node;
}
V hashtable_get_def(HashTable* table, K key, V def) {
    HashNode* node = hashtable_get(table, key);
    return node != NULL ? node->value : def;
}
void hashtable_set(HashTable* table, K key, V value) {
    int hash = key % table->bucketSize;
    while (hash < 0) hash += table->bucketSize;
    HashNode* node = table->buckets[hash], *prenode = NULL;
    while (node != NULL && node->key != key) {
        prenode = node;
        node = node->next;
    }

    if (node != NULL) {
        node->value = value;
    } else {
        HashNode * tmp = malloc(sizeof(HashNode));
        tmp->key = key;
        tmp->value = value;
        tmp->next = NULL;
        if (prenode != NULL) {
            prenode->next = tmp;
        } else {
            table->buckets[hash] = tmp;
        }
        table->eleCount++;
    }
}
HashNode** hashtable_iter(HashTable* table) {
    HashNode* nodes[table->eleCount];
    int i, c = 0;
    for (i = 0 ; i < table->bucketSize ; i++) {
        HashNode* n = table->buckets[i];
        while (n != NULL) {
            nodes[c++] = n;
            n = n->next;
        }
    }
    return nodes;
}
// ----------------------an implentation of HashTable------------------

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    HashTable* table = hashtable_create(numsSize);
    HashNode* node = NULL;
    long i, j, sum = 0, count = 0, diff = upper - lower + 1;
    hashtable_set(table, 0, 1);
    for (i = 0 ; i < numsSize ; i++) {
        sum += nums[i];
        if (diff < table->eleCount) {
            for (j = sum - upper ; j <= sum - lower ; j++) {
                count += hashtable_get_def(table, j, 0);
            }
        } else {
            HashNode** nodes = hashtable_iter(table);
            for (j = 0 ; j < table->eleCount ; j++) {
                if (sum - nodes[j]->key <= upper && sum - nodes[j]->key >= lower) {
                    count += nodes[j]->value;
                }
            }
        }
        hashtable_set(table, sum, hashtable_get_def(table, sum, 0)+1);
    }
    return count;
}
