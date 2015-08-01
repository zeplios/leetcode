/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
    int sum = 0, cursum = 0, top = 0;
    struct TreeNode* stack[1000];
    struct TreeNode* prePop;
    
    struct TreeNode* cur = root;
    while (cur != NULL || top > 0) {
        while (cur) {
            stack[top++] = cur;
            cursum = cursum * 10 + cur->val;
            cur = cur->left;
        }
        cur = stack[top - 1];
        if (cur->left == NULL && cur->right == NULL) {
            sum += cursum;
        }
        if (cur->right != NULL && cur->right != prePop) {
            cur = cur->right;
        } else {
            prePop = cur;
            top--;
            cursum /= 10;
            cur = NULL;
        }
    }
    return sum;
}