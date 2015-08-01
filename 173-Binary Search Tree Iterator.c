/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode *stack[1000];
    int top;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator * bsti = malloc(sizeof(struct BSTIterator));
    bsti->top = 0;
    struct TreeNode *cur = root;
    while (cur) {
        bsti->stack[bsti->top++] = cur;
        cur = cur->left;
    }
    return bsti;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return iter->top > 0;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    if (iter->top <= 0)
        return 0;
    struct TreeNode *cur = iter->stack[--iter->top];
    int ret = cur->val;
    if (cur->right != NULL) {
        cur = cur->right;
        while (cur) {
            iter->stack[iter->top++] = cur;
            cur = cur->left;
        }
    }
    return ret;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    //free(iter->stack);
    //free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */