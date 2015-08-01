/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode* n;
    if (inorderSize == 0) {
        return NULL;
    }
    if (inorderSize == 1) {
        // postorderSize == 0, too
        n = malloc(sizeof(struct TreeNode));
        n->val = inorder[0];
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    int i = 0;
    for ( ; i < inorderSize ; i++) {
        if (inorder[i] == preorder[0]) {
            break;
        }
    }
    n = malloc(sizeof(struct TreeNode));
    n->val = inorder[i];
    n->left = buildTree(&preorder[1], i, inorder, i);
    n->right = buildTree(&preorder[i+1], preorderSize - 1 - i, &inorder[i+1], preorderSize - 1 - i);
    return n;
}