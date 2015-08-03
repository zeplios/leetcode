struct TrieNode {
    char ch;
    bool isfinish;
    struct TrieNode* next;
    struct TrieNode* child;
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode* node = malloc(sizeof(struct TrieNode));
    node->isfinish = false;
    node->child = NULL;
    node->next = NULL;
    return node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    struct TrieNode* cur = root;
    if (*word != '\0') {
        if (cur->child == NULL || cur->child->ch > *word) {
            struct TrieNode* node = trieCreate();
            node->ch = *word;
            node->next = cur->child;
            cur->child = node;
            cur = node;
            insert(cur, word+1);
        } else {
            cur = cur->child;
            while (true) {
                if (cur->ch == *word) {
                    insert(cur, word+1);
                    break;
                } else if (cur->next == NULL || cur->next->ch > *word) {
                    struct TrieNode* node = trieCreate();
                    node->ch = *word;
                    node->next = cur->next;
                    cur->next = node;
                    cur = node;
                    insert(cur, word+1);
                    break;
                } else {
                    cur = cur->next;
                }
            }
        }
    } else {
        cur->isfinish = true;
    }
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    struct TrieNode* cur = root;
    if (*word != '\0') {
        if (cur->child == NULL || cur->child->ch > *word) {
            return false;
        } else {
            cur = cur->child;
            while (cur != NULL) {
                if (cur->ch == *word) {
                    return search(cur, word+1);
                } else if (cur->next == NULL || cur->next->ch > *word) {
                    return false;
                } else {
                    cur = cur->next;
                }
            }
        }
    } else {
        return cur->isfinish;
    }
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    struct TrieNode* cur = root;
    if (*prefix != '\0') {
        if (cur->child == NULL || cur->child->ch > *prefix) {
            return false;
        } else {
            cur = cur->child;
            while (cur != NULL) {
                if (cur->ch == *prefix) {
                    return startsWith(cur, prefix+1);
                } else if (cur->next == NULL || cur->next->ch > *prefix) {
                    return false;
                } else {
                    cur = cur->next;
                }
            }
        }
    } else {
        return true;
    }
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    while (root->child != NULL) {
        struct TrieNode* child = root->child;
        root->child = child->next;
        trieFree(child);
        free(child);
    }
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);