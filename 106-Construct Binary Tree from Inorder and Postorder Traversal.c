/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
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
        if (inorder[i] == postorder[postorderSize-1]) {
            break;
        }
    }
    n = malloc(sizeof(struct TreeNode));
    n->val = inorder[i];
    n->left = buildTree(inorder, i, postorder, i);
    n->right = buildTree(&inorder[i+1], postorderSize - 1 - i, &postorder[i], postorderSize - 1 - i);
    return n;
}