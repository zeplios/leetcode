/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* itoa(int i) {
    bool neg = false;
    if (i < 0) {
        neg = true;
        i = -i; // ignore INT_MIN
    }
    char* res = malloc(20);
    int pos = 19;
    res[pos--] = '\0';
    if (i == 0) {
        res[pos--] = '0';
    }
    while (i != 0) {
        res[pos--] = i % 10 + '0';
        i /= 10;
    }
    if (neg) res[pos--] = '-';
    return res+pos+1;
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** res = malloc(10000* sizeof(char*));
    struct TreeNode* stack[10000];
    (* returnSize) = 0;
    int top = 0, i, j;
    struct TreeNode* cur = root;
    struct TreeNode* lastPop = NULL;
    while (cur || top > 0) {
        while (cur) {
            stack[top++] = cur;
            cur = cur->left;
        }
        cur = stack[top-1];
        if (!cur->left && !cur->right) {
            res[(* returnSize)] = malloc(top*30+1);
            j = 0;
            for (i = 0 ; i < top ; i++) {
                char * tmp = itoa(stack[i]->val);
                memcpy(&res[(* returnSize)][j], tmp, strlen(tmp));
                j += strlen(tmp);
                if (i != top - 1) {
                    res[(* returnSize)][j++] = '-';
                    res[(* returnSize)][j++] = '>';
                }
            }
            res[(* returnSize)++][j] = '\0';
        }
        
        if (cur->right && lastPop != cur->right) {
            cur = cur->right;
        } else {
            lastPop = cur;
            cur = NULL;
            top--;
        }
    }
    return res;
}