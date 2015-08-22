/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct HashNode {
    int key;
    int val;
} HashNode;

typedef struct HashMap {
    int size;
    HashNode** storage;
} HashMap;

HashMap * hash_create(int size){
    HashMap * hashMap = malloc(sizeof(HashMap));
    hashMap->size = size;
    hashMap->storage = calloc(size, sizeof(HashNode*));
    return hashMap;
}

void hash_destroy(HashMap * hashMap) {
	int i;
    for(i = 0 ; i < hashMap->size ; i++) {
        HashNode * node;
        if((node = hashMap->storage[i])) {
            free(node);
        }
    }
    free(hashMap->storage);
    free(hashMap);
}

void hash_set(HashMap * hashMap, int key, int value) {
    int hash = abs(key) % hashMap->size;
    HashNode * node;
    while ((node = hashMap->storage[hash])) {
        if (hash < hashMap->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }
    node = malloc(sizeof(HashNode));
    node->key = key;
    node->val = value;
    hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap * hashMap, int key) {
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (node->key == key) {
            return node;
        }

        if (hash < hashMap->size - 1) {
            hash++;
        } else {
            hash = 0;
        }
    }

    return NULL;
}
int* twoSum(int* nums, int numsSize, int target) {
	HashMap * hashMap = hash_create(numsSize * 2);
	int * res = malloc(sizeof(int) * 2);
    int i, j;
    for (i = 0 ; i < numsSize ; i++) {
        int num2 = target - nums[i];
        HashNode * node = hash_get(hashMap, num2);
        if (node != NULL) {
        	res[0] = node->val + 1;
            res[1] = i + 1;
		} else {
			hash_set(hashMap, nums[i], i);
		}
    }
    return res;
}