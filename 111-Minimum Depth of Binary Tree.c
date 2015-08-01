/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a, int b) {
    return a > b ? b : a;
}
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    else if (root->right == NULL)
        return 1 + minDepth(root->left);
    else
        return 1 + min(minDepth(root->left), minDepth(root->right));
}