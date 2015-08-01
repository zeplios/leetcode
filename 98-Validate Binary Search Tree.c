/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    struct TreeNode* stack[1000];
    int top = 0, pre = INT_MIN;
    bool first = true;
    struct TreeNode* cur = root;
    while (cur || top > 0) {
        while (cur) {
            stack[top++] = cur;
            cur = cur->left;
        }
        cur = stack[--top];
        if (!first && cur->val <= pre) {
            return false;
        } else {
            pre = cur->val;
            first = false;
        }
        if (cur->right != NULL) {
            cur = cur->right;
        } else {
            cur = NULL;
        }
    }
    return true;
}