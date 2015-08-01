/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* ancestor;
    struct TreeNode* cur = root;
    struct TreeNode* stack[10000];
    int top = 0, topAncestor = 0;
    bool findLeft = false;
    while (cur || top > 0) {
        while (cur) {
            stack[top++] = cur;
            if (cur == p || cur == q) {
                if (!findLeft) {
                    topAncestor = top;
                    ancestor = cur;
                    findLeft = true;
                } else {
                    return ancestor;
                }
            }
            cur = cur->left;
        }
        if (findLeft && topAncestor == top) {
            ancestor = stack[--topAncestor];
        }
        cur = stack[--top];
        if (cur->right) {
            cur = cur->right;
        } else {
            cur = NULL;
        }
    }
    return NULL;
}