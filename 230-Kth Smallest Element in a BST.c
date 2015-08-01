/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode* stack[1000];
    int top, smallest = 0;
    struct TreeNode* cur = root;
    while (cur || top > 0) {
        while (cur) {
            stack[top++] = cur;
            cur = cur->left;
        }
        cur = stack[--top];
        if (k == ++smallest) {
            return cur->val;
        }
        if (cur->right) {
            cur = cur->right;
        } else {
            cur = NULL;
        }
    }
    return -1;
}