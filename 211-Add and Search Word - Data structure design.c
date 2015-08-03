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
void trieInsert(struct TrieNode* root, char* word) {
    struct TrieNode* cur = root;
    if (*word != '\0') {
        if (cur->child == NULL || cur->child->ch > *word) {
            struct TrieNode* node = trieCreate();
            node->ch = *word;
            node->next = cur->child;
            cur->child = node;
            cur = node;
            trieInsert(cur, word+1);
        } else {
            cur = cur->child;
            while (true) {
                if (cur->ch == *word) {
                    trieInsert(cur, word+1);
                    break;
                } else if (cur->next == NULL || cur->next->ch > *word) {
                    struct TrieNode* node = trieCreate();
                    node->ch = *word;
                    node->next = cur->next;
                    cur->next = node;
                    cur = node;
                    trieInsert(cur, word+1);
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
bool trieSearch(struct TrieNode* root, char* word) {
    struct TrieNode* cur = root;
    if (*word != '\0') {
        if (cur->child == NULL || (*word != '.' && cur->child->ch > *word)) {
            return false;
        } else {
            cur = cur->child;
            while (cur != NULL) {
                if (cur->ch == *word || *word == '.') {
                    bool res = trieSearch(cur, word+1);
                    if (res) {
                        return true;
                    }
                } else if (cur->next == NULL || cur->next->ch > *word) {
                    return false;
                }
                cur = cur->next;
            }
        }
    } else {
        return cur->isfinish;
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

struct WordDictionary {
    struct TrieNode* root;
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary* wd = malloc(sizeof(struct WordDictionary));
    struct MyTreeNode* root = trieCreate();
    wd->root = root;
    return wd;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
    trieInsert(wordDictionary->root, word);
}
/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) {
    return trieSearch(wordDictionary->root, word);
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    trieFree(wordDictionary->root);
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);