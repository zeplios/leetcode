/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSame(struct TreeNode* l, struct TreeNode* r) {
    if (l == NULL && r == NULL) return true;
    if (l && r && l->val != r->val) return false;
    if ((l && !r) || (!l && r)) return false;
    return isSame(l->left, r->right) && isSame(l->right, r->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return isSame(root->left, root->right);
}