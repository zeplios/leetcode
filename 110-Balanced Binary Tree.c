/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* n) {
    if (n == NULL) return 0;
    if (n->left == NULL && n->right == NULL) return 1;
    int left = n->left ? height(n->left) : 0;
    if (left == -1) return -1;
    int right = n->right ? height(n->right) : 0;
    if (right == -1) return -1;
    if (abs(left - right) > 1) {
        return -1;
    }
    return left > right ? left + 1 : right + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    // if is not balanced, return -1, so -1 + 1 -> false
    return height(root)+1;
}